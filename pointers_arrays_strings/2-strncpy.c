#include "main.h"

/**
 * _strncpy - Copies at most n bytes of string src into dest
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 * @n: Maximum number of bytes to copy
 *
 * Return: Pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
