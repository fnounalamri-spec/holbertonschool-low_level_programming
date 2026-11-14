#include <stdio.h>

/**
 * main - Entry point for the simple calculator skeleton program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice = -1;

	printf("Simple Calculator\n");
	while (choice != 0)
	{
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
			break;
		if (choice == 0)
			printf("Bye!\n");
	}
	return (0);
}
