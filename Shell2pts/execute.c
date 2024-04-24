#include "main.h"
/**
 * _execute - fonction that execute the line after the prompt
 * @command: pointer array
 * Return: 0
*/

int execute_cmd(char *command)
{
	int chld;
	char *args[] = {NULL,  NULL};
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork error");/*creation failed*/
		exit(1);
	}
	if (pid == 0)
	{
		args[0] = command;/*args[0] stock the command from execve*/
		args[1] = NULL;/*args[1] stock the NULL argument from the end of execve*/
		if (strcmp(command, args[0]) == 0)/*compare the command and the user value*/
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./hsh");
				exit(1);
			}
		}
		else
		{
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &chld, 0);/*Wait for the child process to finish*/
	}
	return (0);
}
