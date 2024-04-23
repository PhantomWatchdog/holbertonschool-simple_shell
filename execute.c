#include "main.h"

/**
 * execute_command - Exe user cmd.
 * @command: User command.
 * Return: void.
 */

void execute_command(char *command)
{
	char *args[2];
	int status;
	pid_t pid;

	/* Supprimer le saut de ligne final de la commande*/
	command[strcspn(command, "\n")] = '\0';

	args[0] = command;
	args[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		/* Processus fils : exécute la commande*/
		if (execve(args[0], args, NULL) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Processus parent : attend la fin du processus fils*/
		wait(&status);
	}
}
