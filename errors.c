#include "shell.h"

/**
 * _eputs - a command to print the string inputed
 * @str: the string that is going to be printed
 * Return: nothing
 */
void _eputs(char *str)
{
	int t = 0;

	if (!str)
		return;
	while (str[t] != '\0')
	{
		_eputchar(str[t]);
		t++;
	}
}
/**
 * _eputchar - a function to input a charcter c to stddel
 * @c: the character to be printed
 *
 * Return: 1 on Success
 * on failure return -1 and errno is set collectly
 */
int _eputchar(char c)
{
	static int t;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(2, buffer, t);
		t = 0;
	}
	if (c != BUF_FLUSH)
		buffer[t++] = c;
	return (1);
}
/**
 * _putfd - acommand to input a charceter c given fd
 * @c: the character to be printed
 * @fd: The file description to write in it
 * Return: 1 on success, -1 on failure and errno is set collectly
 */
int _putfd(char c, int fd)
{
	static int t;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, t);
		t = 0;
	}
	if (c != BUF_FLUSH)
		buffer[t++] = c;
	return (1);
}
/**
 * _putsfd - a command to prints a string inputed
 * @str: the string that is going to be printed
 * @fd: the file that descript what to write
 * Return: the numbe of charecter to insert
 */
int _putsfd(char *str, int fd)
{
	int t = 0;

	if (!str)
		return (0);
	while (*str)
	{
		t += _putfd(*str++, fd);
	}
	return (t);
}
