#include "main.h"

/**
 * read_command - cmd read.
 * @buffer: tampon
 * @read_result: resultat
 * return: void
 */

void read_command(char *buffer, ssize_t *read_result)
{
	size_t length;

	*read_result = read(STDIN_FILENO, buffer, BUFFER_SIZE);

	if (*read_result < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	length = (size_t)(*read_result);

	if (buffer[length - 1] == '\n')
	{
		buffer[length - 1] = '\0';
	}
}
