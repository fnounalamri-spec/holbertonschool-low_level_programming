#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers
 * @a: Pointer to the array of integers
 * @n: Number of elements of the array
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int tmp;

	while (i < n / 2)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
		i++;
	}
}
