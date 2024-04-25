#include "main.h"

/**
 * execute_cmd - Exe usr_input send by prompt.
 * @usr_input: Input received from user.
 * Return: 0
*/

int execute_cmd(char *usr_input)
{
	int status;

	/* Stock the command args */
	char *args[] = {NULL, NULL, NULL};

	/* Create a new process */
	pid_t pid = fork();

	/* If error in process creation */
	if (pid == -1)
	{
		perror("fork error");
		exit(1);
	}

	/* If process creation success */
	if (pid == 0)
	{
		args[0] = usr_input;

		/* Parse command with delimiter */
		args[1] = strtok(NULL, " ");
		args[2] = NULL;

		if (strcmp(usr_input, args[0]) == 0)
		{
			/* Check if command exe fail */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./hsh");
				exit(1);
			}
		}
	}
	else
	{
		/* Pause ppid - 0 for standard use of func */
		waitpid(pid, &status, 0);
	}
	return (0);
}
