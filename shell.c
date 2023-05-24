#include "shell.h"

/**
 * read_command - Read user input from stdin
 * @command: Buffer to store the user input
 */
void read_command(char *command)
{
	fgets(command, READ_BUF_SIZE, stdin);

	if (command[strlen(command) - 1] == '\n')
		command[strlen(command) - 1] = '\0';
}

/**
 * parse_command - Parse the command into individual arguments
 * @command: User input command
 * @args: Array to store the parsed arguments
 */
void parse_command(char *command, char **args)
{
	char *token;
	int i = 0;

	token = strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}

/**
 * execute_command - Execute the command by forking a new process
 * @args: Array of command arguments
 * Return: 1 on success
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char command[READ_BUF_SIZE];
	char *args[BUF_FLUSH];

	while (1)
	{
		printf("$ ");
		read_command(command);
		parse_command(command, args);
		execute_command(args);
	}

	return (0);
}
