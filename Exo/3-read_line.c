#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print $ and wait user input.
 * Return: 0.
 */

int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	if (buffer == NULL)
	{
		perror("Failed to allocate memory");
		return (1);
	}

	while (1)
	{
		printf("$ ");
		size_t read_bytes = getline(&buffer, &len, stdin);

		if (read_bytes == -1)
		{
			perror("Error reading input");
			break;
		}

		printf("%s", buffer);
	}

	free(buffer);
	return (0);
}
