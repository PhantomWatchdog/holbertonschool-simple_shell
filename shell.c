#include "shell.h"

/**
 * main - Display prompt.
 * @ac: Arguments count.
 * @argv: Arguments values.
 * Return: 0.
*/

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0;

	(void)ac, (void)argv;

	printf("%s", prompt);

	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}
