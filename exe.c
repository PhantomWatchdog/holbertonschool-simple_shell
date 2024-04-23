#include "shell.h"

/**
 * execshell - Command exe.
 * @argv: Arguments values.
 * Return: void.
*/

void execshell(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
	}
}
