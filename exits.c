#include "shell.h"
/**
 * _strncpy - A function that copy the string
 * @dest: A prace where  string will be copied to
 * @src: A source of the string we copied
 * @n: Amount of characters copied in the program
 * Return: appende string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int q, w;

	char *v = dest;

	q = 0;
	while (src[q] != '\0' && q < n - 1)
	{
		dest[q] = src[q];
		q++;
	}
	if (q < n)
	{
		w = q;
		while (w < n)
		{
			dest[w] = '\0';
			w++;
		}
	}
	return (v);
}
/**
 * _strncat - afunction to append two strings together
 * @dest: the first string to be added
 * @src: the second string to be added to first
 * @n: The amount of bytes needed to maximeze
 * Return: the appended string
 */
char *_strncat(char *dest, char *src, int n)
{
	int q, w;
	char *v = dest;

	q = 0;
	w = 0;
	while (dest[q] != '\0')
		q++;
	while (src[w] != '\0' && w < n)
	{
		dest[q] = src[w];
		q++;
		w++;
	}
	if (w < n)
		dest[q] = '\0';
	return (v);
}
/**
 * _strchr - A function to locates a character in A string
 * @s: The string that is goin to be parsed in
 * @c: the character inputed to look for
 * Return: (s) A pointer to the memory address
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
