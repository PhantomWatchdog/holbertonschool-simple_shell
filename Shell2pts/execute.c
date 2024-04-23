#include "main.h"

/**
 * execute_command - Exe user cmd.
 * @buffer: User command.
 * Return: void.
 */

void execute_command(char *buffer)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[2];

		args[0] = buffer;
		args[1] = NULL;
		execve(args[0], args, __environ);

		perror(buffer);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
