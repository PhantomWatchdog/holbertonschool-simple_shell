#include "main.h"

/**
 * main - Prompt core.
 * Return: 0.
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int read_bytes;

	while (1)
	{
		prompt(); /* Affiche le prompt du shell*/

		/* Lire la commande entrée par l'utilisateur*/
		read_bytes = getline(&buffer, &bufsize, stdin);

		if (read_bytes == -1)
		{
			break; /* Quitter si getline() échoue*/
		}

		execute_command(buffer); /* Exécuter la commande saisi*/
	}

	free(buffer); /* Libérer la mémoire allouée pour le buf*/

	return (0);
}

