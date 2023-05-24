#include "shell.h"

/**
 * input_buf - A function to input buffer chained command
 * @info: A structure of parameter inputed to hold particulary arguments
 * @buf: aspecific adress of a buffer
 * @len: a specific adress of lenght of var
 *
 * Return: Abytes of input
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t t = 0;
	size_t len_v = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		t = getline(buf, &len_v, stdin);
#else
		t = _getline(info, buf, &len_v);
#endif
		if (t > 0)
		{
			if ((*buf)[t - 1] == '\n')
			{
				(*buf)[t - 1] = '\0';
				t--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = t;
				info->cmd_buf = buf;
			}
		}
	}
	return (t);
}
/**
 * get_input - a program to get a line minus a new line
 * @info: a structured parameter of function to hold a particulary arguments
 *
 * Return: A bytes of input
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t w, q, len;
	ssize_t t = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	t = input_buf(info, &buf, &len);
	if (t == -1)
		return (-1);
	if (len)
	{
		q = w;
		p = buf + w;

		check_chain(info, buf, &q, w, len);
		while (q < len)
		{
			if (is_chain(info, buf, &q))
				break;
			q++;
		}
		w = q + 1;
		if (w >= len)
		{
			w = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (t);
}
/**
 * read_buf - a program to input a buffer
 * @info: a parameter of a structure that holds the particulary arguments
 * @buf: adress of buffer
 * @i: size of buffer
 * Return: r always
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}
/**
 * _getline - a program to gets a next line of input from stdin
 * @info: a paramater of structure that holds a particurly arguments
 * @ptr: an adress of poinetr to buffer with
 * @length: the size of preallocated ptr buffer if is not a null
 * Return: s always
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t t, len;
	size_t q;
	ssize_t n = 0, m = 0;
	char *a = NULL, *new_p = NULL, *b;

	a = *ptr;
	if (a && length)
		m = *length;
	if (t == len)
		t = len = 0;
	n = read_buf(info, buf, &len);
	if (n == -1 || (n == 0 && len == 0))
		return (-1);
	b = _strchr(buf + t, '\n');
	q = b ? 1 + (unsigned int)(b - buf) : len;
	new_p = _realloc(a, m, m ? m + q : q + 1);
	if (!new_p)
		return (a ? free(a), -1 : -1);
	if (m)
		_strncat(new_p, buf + t, q - t);
	else
		_strncpy(new_p, buf + t, q - t + 1);
	m += q - t;
	t = q;
	a = new_p;

	if (length)
		*length = m;
	*ptr = a;
	return (m);
}
/**
 * sigintHandler - Blocks of ctrl-C inputed
 * @sig_num: the signal numbe to be inserted
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
