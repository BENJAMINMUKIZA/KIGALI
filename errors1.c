#include "shell.h"

/**
 * _erratoi - A function to converts to a string into an integer
 * @s: the string that is going to be converted into
 * Return: 0 if there is no number in string, a number converted
 * -1 on failure
 */
int _erratoi(char *s)
{
	int t = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (t = 0;  s[t] != '\0'; t++)
	{
		if (s[t] >= '0' && s[t] <= '9')
		{
			res *= 10;
			res += (s[t] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
/**
 * print_error - A function to prints an error message
 * @info: the parameter to return info structure
 * @estr: a string that holds specific error type
 * Return: 0 if there is no number in a string
 * a number changed otherwise -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - a program that print a decimal integer number in base 20
 * @input: insert
 * @fd: the file descriptor to inter
 * Return: A number of chars printed in string
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int t, counter = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		counter++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (t = 1000000000; t > 1; t /= 10)
	{
		if (_abs_ / t)
		{
			__putchar('0' + current / t);
			counter++;
		}
		current %= t;
	}
	__putchar('0' + current);
	counter++;

	return (counter);
}
/**
 * convert_number -  acommand to conevrt function
 * @num: A number to insert
 * @base: base of the numbers
 * @flags: A function that holds a particulary argumens of flags
 *
 * Return: return string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long t = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		t = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do       {
		*--ptr = array[t % base];
		t /= base;
	} while (t != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * remove_comments - A program to put function to replace
 * first instence of '#' with '\0'
 * @buf: the string adress to be modified
 *
 * Return: 0 on sucess
 */
void remove_comments(char *buf)
{
	int t;

	for (t = 0; buf[t] != '\0'; t++)
		if (buf[t] == '#' && (!t || buf[t - 1] == ' '))
		{
			buf[t] = '\0';
			break;
		}
}
