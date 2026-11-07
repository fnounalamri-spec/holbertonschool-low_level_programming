#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints digits 0 to 9 using only putchar
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	n = 0;
	while (n < 10)
	{
		putchar(n + '0');
		n++;
	}
	putchar('\n');
	return (0);
}
