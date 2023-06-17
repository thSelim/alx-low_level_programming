#include <stdio.h>

/**
 * main - entry point
 *
 * Description: greater & less than
 *
 * Return: 0 (Success)
*/

int main(void)
{
	int i;

	for (i = 'z'; i >= 'a'; i--)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
