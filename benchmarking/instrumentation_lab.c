#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

/**
 * next_value - Generates the next pseudo-random unsigned integer
 * @state: Pointer to the current state
 *
 * Return: The updated state value
 */
static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

/**
 * build_dataset - Populates the static dataset array with values
 */
static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

/**
 * process_dataset - Performs arithmetic transformations on the dataset
 */
static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

/**
 * reduce_checksum - Computes a rolling checksum over the dataset
 *
 * Return: The computed checksum as unsigned long
 */
static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

/**
 * main - Entry point for the controlled instrumentation experiment
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long checksum;
	clock_t total_start, total_end;
	clock_t build_start, build_end;
	clock_t process_start, process_end;
	clock_t reduce_start, reduce_end;
	double total_sec, build_sec, process_sec, reduce_sec;

	total_start = clock();

	build_start = clock();
	build_dataset();
	build_end = clock();

	process_start = clock();
	process_dataset();
	process_end = clock();

	reduce_start = clock();
	checksum = reduce_checksum();
	reduce_end = clock();

	total_end = clock();

	if (checksum == 0ul)
		printf("impossible\n");

	total_sec = (double)(total_end - total_start) / CLOCKS_PER_SEC;
	build_sec = (double)(build_end - build_start) / CLOCKS_PER_SEC;
	process_sec = (double)(process_end - process_start) / CLOCKS_PER_SEC;
	reduce_sec = (double)(reduce_end - reduce_start) / CLOCKS_PER_SEC;

	printf("TOTAL seconds: %.6f\n", total_sec);
	printf("BUILD_DATA seconds: %.6f\n", build_sec);
	printf("PROCESS seconds: %.6f\n", process_sec);
	printf("REDUCE seconds: %.6f\n", reduce_sec);

	return (0);
}
