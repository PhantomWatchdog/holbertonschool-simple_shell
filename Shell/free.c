#include "shell.h"

/**
 * free_error - frees alloc'd pointers following system error
 * @argv: pointer to a pointer to an array of pointers
 * @arg: pointer to a pointer to an array of characters
 *
 * Return: void.
 */

void free_error(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */

void free_tokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}

/**
 * free_path - Frees the global variable containing the PATH environment
 *              variable value
 *
 * Return: Nothing
 */

void free_path(void)
{
	if (environ != NULL)
	{
		size_t i = 0;

		while (environ[i] != NULL)
		{
			if (strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}

static char *last_input;

/**
 * free_last_input - Frees the most recent input entered by the user.
 *
 * This function frees the memory allocated for the most recent input string
 * entered by the user. It should be called after the input string is no longer
 * needed.
 */

void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
