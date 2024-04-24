#include "main.h"

/**
 * main - Prompt core.
 * Return: 0.
*/

int main(void)
{
	char *usr_input;
	char *buffer;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt();
			buffer = _getinput();
		}

		if (buffer == NULL)
		{

			break;
		}

		usr_input = strtok(buffer, " ");

		if (usr_input != NULL)
		{
			execute_cmd(usr_input);
		}

		free(buffer);
	}

	return (0);
}
