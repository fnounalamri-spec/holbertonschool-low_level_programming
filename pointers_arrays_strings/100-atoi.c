#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string to convert
 *
 * Return: The converted integer, or 0 if no numbers are found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			res = (res * 10) - (s[i] - '0');
		}
		else if (found)
			break;
		i++;
	}

	if (sign > 0)
		res = -res;

	return (res);
}
