#include "main.h"

/**
 * main - entry point
 * @av: arguments in the stdin
 * @ac: numbers of arguments
 *
 * Return: 0 for success.
*/

int main(int ac, char **av)
{
	char *line = NULL;
	char **tokens;
	int status = 0, pathnumb = 0;
	(void)ac;


	while (1)
	{
		errno = 0;

		line = _getline();
		if (line == NULL && errno == 0)
		{
			exit(1);
		}
			if (line)
			{
				pathnumb++;
				tokens = _strtok(line);
				if(tokens == NULL)
					free(line);
				status = process(tokens, av, pathnumb);
				free(tokens);
				free(line);
				if (status == 42)
				{
					exit(0);
				}
			}
			else
			{
				if (isatty(STDIN_FILENO))
				{
					write(STDOUT_FILENO, "\n", 1);
				}
				exit(status);
			}

	}
	exit(status);
}
