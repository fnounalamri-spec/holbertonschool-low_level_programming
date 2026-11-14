#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: Pointer to the string to be reversed
 */
void rev_string(char *s)
{
	int len = 0;
	int i = 0;
	char tmp;

	while (s[len] != '\0')
		len++;

	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
		i++;
	}
}
