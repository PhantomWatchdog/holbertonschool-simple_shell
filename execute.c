#include "main.h"

/**
 * execute_cmd - Exe usr_input send by prompt.
 * @usr_input: Input received from user.
 * Return: 0
*/

int execute_cmd(char *usr_input)
{
	int status, count = 0;
	char *args[length] /*= {NULL,  NULL}*/;
	char *token = strtok(NULL, " ");
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		exit(1);
	}

	if (pid == 0)
	{
		/**args[0] = usr_input;
		args[1] = NULL;*/
		args[count++] = usr_input;

		while (token != NULL && count < length - 1)
		{
			args[count++] = token;
		}
		args[count] = NULL;

		/*if (strcmp(usr_input, args[0]) == 0){*/
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./hsh");
				exit(1);
			}
		/*}*/
		else
		{
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
