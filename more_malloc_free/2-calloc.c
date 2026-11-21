#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to the memory, or NULL on failure or if nmemb/size is 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int total, i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < total; i++)
		p[i] = 0;
	return (p);
}
