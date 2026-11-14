#include "main.h"

/**
 * _strstr - Locates a substring
 * @haystack: Pointer to the string to be searched
 * @needle: Pointer to the substring to locate
 *
 * Return: Pointer to the beginning of the located substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (needle[j] == '\0')
			return (haystack + i);
	}

	return (0);
}
