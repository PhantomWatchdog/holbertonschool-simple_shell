#include "main.h"
/**
 * _getline - function tu read the line after the prompt
 * Return: the line.
*/

char *_getinput(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t read_buffer;


	read_buffer = getline(&buffer, &size, stdin);

	if (read_buffer <= 0)
	{
		free(buffer);
		return (0);
	}

	if (buffer[read_buffer - 1] == '\n')
	{
		buffer[read_buffer - 1] = '\0';
	}
	return (buffer);
}
