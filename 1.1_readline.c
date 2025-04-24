#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the command the user inputs
 *
 * Return: Number of characters in the input
 */

int main(void)
{
	char* line = NULL;
	size_t len = 0;
	int num_char = 0;

	while (1)
	{
		printf("$ ");

		num_char = getline(&line, &len, stdin);
		if (num_char == -1)
			break;

		printf("%s", line);
	}
	
	free(line);	
	return (num_char);
}
