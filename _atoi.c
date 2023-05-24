#include "shell.h"
/**
 * interactive - A function to return true in an inteactive mode
 * @info: atype of structured adress
 *
 * Return: Always 1 on sucess and 0 on failure
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - afunction that checks if char is delimeter
 * @c: the character to check the del
 * @delim: the delimeter of the string used
 * Return: Always 1 if yes or 0 if not
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - A function to check if the character is alphabet
 * @c: inputed character
 * Return: Always return 1 if alphabet or 0 if not
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - a func to convert a string to an integer
 * @s: the string to be converted into integer
 * Return: Always 0 if no number in string , otherwise converted number
 */
int _atoi(char *s)
{
	int a, sign = 1, flg = 0, write;
	unsigned int result = 0;

	for (a = 0;  s[a] != '\0' && flg != 2; a++)
	{
		if (s[a] == '-')
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flg = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flg == 1)
			flg = 2;
	}
	if (sign == -1)
		write = -result;
	else
		write = result;
	return (write);
}
