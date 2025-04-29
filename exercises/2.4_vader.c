#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork + wait + execve
 *
 * Description: Write a program that executes the command ls -l /tmp in 5
 * different child processes. Each child should be created by the same process
 * (the father). Wait for a child to exit before creating a new child.
 *
 * Return: Success (0) or Failure (-1)
 */

int main (void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL}; 
	pid_t child_pid;
	int status;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork failed:");
			return (-1); 
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve failed:");
				return (-1);
			}
		}
		else
			wait(&status);
	}

	return (0);
}
