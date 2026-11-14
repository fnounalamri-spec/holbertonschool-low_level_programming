# Green Efficiency Analysis

## Measurement Methodology

To evaluate execution efficiency and identify performance bottlenecks across distinct computational stages, the program `instrumentation_lab.c` was instrumented using the standard C `<time.h>` library. Specifically, `clock_t` variables and the `clock()` function were placed immediately before and after each functional phase to capture processor ticks consumed by the process. Raw tick differences were converted into wall-clock CPU seconds by dividing by `CLOCKS_PER_SEC` and formatted to six decimal places (`%.6f`).

Four distinct measurement boundaries were established:
- **TOTAL**: Wraps the entire execution pipeline from before `build_dataset()` until after `reduce_checksum()` completes.
- **BUILD_DATA**: Isolates `build_dataset()`, which generates 50,000 deterministic pseudo-random integers using a linear congruential generator.
- **PROCESS**: Isolates `process_dataset()`, which performs arithmetic transformations (multiplication, integer division, modulo, and conditional sign negation) across all 50,000 array elements.
- **REDUCE**: Isolates `reduce_checksum()`, which sequentially aggregates all elements into a single rolling `unsigned long` checksum.

Consistent boundaries were maintained across runs by excluding `printf()` formatting overhead from the timed blocks and keeping all algorithmic logic strictly unchanged.

## Observed Performance Differences

Compiling with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89` and executing the instrumented binary produced the following representative timing profile:

- `TOTAL seconds: 0.001412`
- `BUILD_DATA seconds: 0.000438`
- `PROCESS seconds: 0.000795`
- `REDUCE seconds: 0.000168`

The measurements demonstrate that `PROCESS` is the dominant consumer of execution time, accounting for approximately 56.3% (`0.000795 s`) of the total runtime (`0.001412 s`). `BUILD_DATA` represents the second-largest share at roughly 31.0% (`0.000438 s`), whereas `REDUCE` is the fastest phase at 11.9% (`0.000168 s`). The sum of the three isolated phases (`0.001401 s`) is slightly lower than `TOTAL` (`0.001412 s`), with the remaining `0.000011 s` reflecting minor measurement overhead between consecutive `clock()` calls. `PROCESS` takes nearly 4.7 times longer than `REDUCE` because each iteration executes expensive integer division (`/ 7`) and modulo (`% 11`) instructions alongside conditional branching, while `REDUCE` performs only a single multiply-accumulate operation per element.

## Relation Between Runtime and Energy Consumption

In computing systems, energy consumption ($E$) is directly governed by the relationship $E = P \times t$, where $P$ is average power draw in watts and $t$ is active execution time in seconds. When a CPU core executes arithmetic-heavy loops such as `process_dataset()`, it remains in an active, high-frequency power state (C0 state) rather than entering low-power idle states. Consequently, phases with longer CPU runtimes directly translate into higher joules consumed per execution. Reducing the runtime of `PROCESS` from `0.000795 s` toward the efficiency of `REDUCE` (`0.000168 s`) would proportionally decrease total active CPU cycles and lower energy expenditure at scale.

## Limitations of the Experiment

Several constraints limit the generalizability of these measurements:
1. **Timer Resolution and Short Duration**: With a dataset of `50,000` elements, total execution finishes in under two milliseconds (`0.001412 s`), approaching the granularity limits of `clock()` on virtualized Linux environments, where OS scheduler jitter can introduce noticeable variance between runs.
2. **Lack of Direct Hardware Power Telemetry**: `clock()` measures CPU time rather than actual electrical power draw (such as Intel RAPL energy counters), meaning variations in memory bus activity or dynamic frequency scaling are inferred rather than directly measured.
3. **Cache Warmup Effects**: Static array allocation keeps all 50,000 integers (`200 KB`) comfortably inside L2/L3 CPU caches, masking main memory latency bottlenecks that occur in larger workloads.

## Practical Engineering Takeaway

Empirical instrumentation prevents premature optimization by pinpointing exact hotspots. Rather than refactoring `reduce_checksum()`, which consumes only `0.000168 s`, engineering effort should target `process_dataset()` (`0.000795 s`), where replacing costly division and modulo operations with bitwise shifts or strength-reduced arithmetic yields the highest reduction in both latency and energy consumption.
