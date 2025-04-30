#include <stdio.h>

char *get_path(char *command);  // Declare the function prototype

int main(void)
{
	char *command = "mkdi123123r";  // You can use any dummy command for now

	printf("Testing get_path with command: %s\n\n", command);
	char* output = get_path(command);
	printf("test file get_path: %s\n", output);

	return 0;
}
