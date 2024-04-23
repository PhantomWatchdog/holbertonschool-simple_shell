#include "main.h"

/**
 * main - Init of prompt.
 * @av: Stdin fd stocking args.
 * @ac: Arguments number.
 * Return: 0.
*/

int main(int ac, char **argv)
{
	char *prompt = "Guantanamo$ ", *token;
	char *buffer = NULL, *buffer_cpy = NULL;
	size_t nbytes = 0;
	ssize_t nchar_read;
	const char *delim = " \n";
	int n_token = 0, i = 0;
	(void)ac;

	while (1)
	{

		printf("%s", prompt);
		nchar_read = getline(&buffer, &nbytes, stdin);

		if (nchar_read == -1)
		{
			printf("Exit shell\n");
			return (-1);
		}

		buffer_cpy = malloc(sizeof(char) * nchar_read);

		if (buffer_cpy == NULL)
		{
			perror("Guantanamo: cell allocation error");
			return (-1);
		}
		
		strcpy(buffer_cpy, buffer);

		token = strtok(buffer, delim);
		 
		while (token != NULL)
		{
			n_token++;
			token = strtok(NULL, delim);
		}

		n_token++;
		
		argv = malloc(sizeof(char *) * n_token);
		
		token = strtok(buffer_cpy, delim);
		
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);
	}
	
	free(buffer_cpy);
	free(buffer);
	
	return (0);
}
