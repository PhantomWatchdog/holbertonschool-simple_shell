#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print all the arguments without ac use.
 * @ac: Argument count.
 * @av: Argument values.
 * Return: 0
 */

int main(int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
