#include "main.h"

/**
 * main - Prompt core.
 * Return: 0.
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_result;

	while (1)
	{
		char *token;

		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		read_command(buffer, &read_result);

		if (read_result == 0)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			break;
		}

		token = strtok(buffer, "\n");
		while (token != NULL)
		{
			execute_command(token);
			token = strtok(NULL, "\n");
		}
	}

	return (EXIT_SUCCESS);
}

