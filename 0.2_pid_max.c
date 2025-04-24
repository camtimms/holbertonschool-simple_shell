#include <stdio.h>
#include <unistd.h>

/**
 * main - Prints PID_MAX
 *
 * Return: Success (0) or failure (1)
 */
int main(void)
{
	int pid_max;

	FILE *fp = fopen("/proc/sys/kernel/pid_max", "r");
	if (fp == NULL)
	{
		perror("Error opening file");
		return (-1);
	}
	
	fscanf(fp, "%d", &pid_max);
	fclose(fp);

	printf("%d\n", pid_max);
	return (0);
}
