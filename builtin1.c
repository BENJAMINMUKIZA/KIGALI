#include "shell.h"
/**
 * _myhistory - show the lists of history, one command by line,
 * preceded with line numbers, biggining from 0.
 * @info: A structure that holds the potential arguments and is used to keep
 * function prototype at rest
 * Return: ALways 0 on success
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - puts an alias on string
 * @info: A parameter strucure of string
 * @str: an alias string
 *
 * Return: ALywas 0 on sucess, 1 on failure
 */
int unset_alias(info_t *info, char *str)
{
	char *v, w;
	int res;

	v = _strchr(str, '=');
	if (!v)
		return (1);
	w = *v;
	*v = 0;
	res = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*v = w;
	return (res);
}
/**
 * set_alias - puts  alias to string
 * @info: A parameter of structure
 * @str: the string of an alias
 *
 * Return: always 0 on pass, 1 on failure
 */
int set_alias(info_t *info, char *str)
{
	char *v;

	v = _strchr(str, '=');
	if (!v)
		return (1);
	if (!*++v)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - A function to print an alias string
 * @node: The alias node of the program
 * Return: Always 0 on pass, 1 on failure
 */
int print_alias(list_t *node)
{
	char *v = NULL, *w = NULL;

	if (node)
	{
		v = _strchr(node->str, '=');
		for (w = node->str; w <= v; w++)
			_putchar(*w);
		_putchar('\'');
		_puts(v + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - a command to mimics the alias builtin program
 * @info: Astructure that holds potential arguments used to
 * keep function prototype  at rest
 * Return: 0 on suceess
 */
int _myalias(info_t *info)
{
	int t = 0;
	char *v = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (t = 1; info->argv[t]; t++)
	{
		v = _strchr(info->argv[t], '=');
		if (v)
			set_alias(info, info->argv[t]);
		else
			print_alias(node_starts_with(info->alias, info->argv[t], '='));
	}
	return (0);
}
