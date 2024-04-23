#include "shell.h"

/**
 * strtok_custom - Parse input and tokenize them.
 * @str: String(input) to strtok.
 * @delim: Delimiter for strtok func.
 * Return: Array.
*/

char **strtok_custom(char *str, const char *delim)
{
	char **argv, *token, *str_copy;
	int i = 0, num_tokens = 0;

	if (str == NULL || delim == NULL)
	{
		return (NULL);
	}
	str_copy = strdup(str);
	if (str_copy == NULL)
	{
		perror("Error allocation memory");
		return (NULL);
	}
	token = strtok(str_copy, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * (num_tokens + 1));
	if (argv == NULL)
	{
		perror("Error allocating memory");
		free(str_copy);
		return (NULL);
	}
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(str_copy);
	return (argv);
}
