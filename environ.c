#include "shell.h"


/**
 * _myenv - A function to print the current env
 * @info: A structu that holds A potential arg
 * used to keep constant funx prototype
 * Return: alwys 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - this is the a func to get the value
 * of an environ vaiable
 * @info: A structure that holds main arg used to keep
 * constatnt prototype
 * @name: the name of an environment
 * Return: always rturn the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *t_node = info->env;
	char *v;

	while (t_node)
	{
		v = starts_with(t_node->str, name);
		if (v && *v)
			return (v);
		t_node = t_node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - A function to initialize the new environ
 * variable or to change the existing one
 * @info: A structure holding potential args and used to keep
 * constan function prototype
 * Return: on success 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - a function to remove or delete
 * an environ variable
 * @info: structure holding potential arguments
 * Return: always 0
 */
int _myunsetenv(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);
	return (0);
}
/**
 * populate_env_list - apopulate function of environ linked list
 * @info: A structure that hold the potential arguments
 * used to keep cons func prototype
 * Return: alwys 0
 */
int populate_env_list(info_t *info)
{
	list_t *t_node = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		add_node_end(&t_node, environ[v], 0);
	info->env = t_node;
	return (0);
}
