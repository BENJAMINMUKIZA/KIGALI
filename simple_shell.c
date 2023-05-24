#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * main - check the code inserted
 *
 * Return: ALWys 0
 */
int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		size_t length = strlen(buffer);

		if (length > 0 && buffer[length - 1] == '\n')
			buffer[length - 1] = '\0';

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(buffer, buffer, NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			int status;

			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
