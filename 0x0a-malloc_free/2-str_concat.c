#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: first string (NULL is treated as empty)
 * @s2: second string (NULL is treated as empty)
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
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
	res = malloc(sizeof(char) * (l1 + l2 + 1));
	if (res == NULL)
		return (NULL);
	for (i = 0; i < l1; i++)
		res[i] = s1[i];
	for (j = 0; j <= l2; j++)
		res[i + j] = s2[j];
	return (res);
}
