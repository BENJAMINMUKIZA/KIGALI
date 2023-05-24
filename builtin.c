#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _myexit - the command to esxits the program
 * @info: A structure that holds a potential arguments
 * and keeps functions prototype at state
 * Return: solte with a A given solte status
 * (0) if info.arg[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _atoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - afunction to change directory ares or current one
 * @info: A structure hold the potential arguments of
 * to maintain the funciolaity of prototype
 * Return: Alwyas 0 on suceess
 */
int _mycd(info_t *info)
{
	char *t, *dir, buffer[2048];
	int chdir_ret;

	t = getcwd(buffer, 2048);
	if (!t)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
		_puts(t);
		_putchar('\n');
		return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 2048));
	}
	return (0);
}
/**
 * _myhelp - Afunction to change the process of the current directory
 * @info: Astructure that holds the potential atrguments used
 * to keep the functio prototype at rest
 * Return: 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
