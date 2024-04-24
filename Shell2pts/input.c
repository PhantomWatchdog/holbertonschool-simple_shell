#include "main.h"
/**
 * _getline - function tu read the line after the prompt
 * Return: the line.
*/

char *_getinput(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t read_line;


	read_line = getline(&line, &size, stdin);/*read input data of line & size*/

	if (read_line <= 0)
	{
		free(line);
		return (0);
	}

	if (line[read_line - 1] == '\n')
	{
		line[read_line - 1] = '\0';
	}
	return (line);
}
