#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: A C progam that prints with printf function.
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	printf("Size of char: %u byte(s)\n", sizeof(char));
	printf("Size of int: %u byte(s)\n", sizeof(int));
	printf("Size of long int: %u byte(s)\n", sizeof(long int));
	printf("Size of long long int: %u byte(s)\n", sizeof(long long int));
	printf("Size of float: %u byte(s)\n", sizeof(float));
	return (0);
}
