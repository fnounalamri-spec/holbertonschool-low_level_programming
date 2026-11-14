#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: Pointer to the string to search
 * @c: The character to locate
 *
 * Return: Pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}

	if (s[i] == c)
		return (s + i);

	return (0);
}
