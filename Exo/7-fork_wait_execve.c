#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Fork + Wait + Execve.
 * Return: Always 0.
 */

int main(void)
{
	pid_t my_pid;
	pid_t child_pid = 1;
	int i = 0;
	int status;
	char *argv[] = {"bin/ls", "-l", "tmp/", NULL};

	my_pid = getpid();

	/* Create multiple child processes */
	while (i <= 4 && (child_pid != 0))
	{
		/* Create a new child process */
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("error");
			return (1);
		}

		/* Parent wait for child process end */
		wait(&status);
		i++;
	}
	
	/* Code executed by child processes */
	if (child_pid == 0)
	{
		printf("--------------------------------\n\n");
		printf("ID CHILD: %u\n\nID PARENT: %u\n\n", getpid(), getppid());
		printf("--------------------------------\n\n");

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("ERROR:");
		}
	}
	else
	{
		printf("%u IS THE PARENT AND MY ID IS: %u\n", my_pid, child_pid);
	}

	return (0);
}
