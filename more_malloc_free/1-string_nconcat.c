#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates s1 with the first n bytes of s2
 * @s1: first string (NULL is treated as empty)
 * @s2: second string (NULL is treated as empty)
 * @n: number of bytes of s2 to use
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *res;
	unsigned int l1, l2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	l1 = 0;
	while (s1[l1] != 0)
		l1++;
	l2 = 0;
	while (s2[l2] != 0)
		l2++;
	if (n >= l2)
		n = l2;
	res = malloc(sizeof(char) * (l1 + n + 1));
	if (res == NULL)
		return (NULL);
	for (i = 0; i < l1; i++)
		res[i] = s1[i];
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];
	res[i + j] = 0;
	return (res);
}
