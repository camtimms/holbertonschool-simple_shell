#include <stdio.h>

/**
 * main - Prints the arguments passed
 *
 * Return: Success (0)
 */

int main(int argc, char* argv[])
{
	int i = 0;

	printf("Number of arguments: %d\n", argc);
	
	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
