#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: Pointer to the string to be printed
 */
void puts_half(char *str)
{
	int len = 0;
	int start, i;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		start = len / 2;
	else
		start = len - ((len + 1) / 2);

	for (i = start; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
