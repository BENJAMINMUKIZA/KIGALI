#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - the prompt for the user to enter a command.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * execute_command - Execute the command using execve.
 * @command: The command to be executed
 *
 * Return: No return value
 */
void execute_command(char *command)
{
	if (strlen(command) > 0)
	{
		char *args[] = {command, NULL};

		execve(command, args, NULL);

		fprintf(stderr, "%s: No such file or directory\n", command);
		exit(1);
	}
}
/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid < 0)
		{
			fprintf(stderr, "Fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			execute_command(command);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
