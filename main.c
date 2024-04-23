#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Same than name.
 */
void display_prompt(void)
{
	printf("MyShell$ ");
	fflush(stdout);
}
/**
 * main - Core function.
 * Return: void.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(command, command, (char *)NULL) == -1)
			{
				fprintf(stderr, "Command not found: %s\n", command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}
