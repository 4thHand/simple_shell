#include "shell.h"

/**
 * _miex - exits the shell
 * @inform: Structure containing potential arguments.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _miex(info_t *inform)
{
	int excheck;

	if (inform->argv[1]) /* If there is an exit arguement */
	{
		excheck = _erratoinie(info->argv[1]);
		if (excheck == -1)
		{
			inform->stat = 2;
			display_err(info, "Illegal number: ");
			_eputtss(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inform->er_numb = _erratoinie(inform->argv[1]);
		return (-2);
	}
	inform->er_numb = -1;
	return (-2);
}

/**
 * _micd - changes the current directory of the process
 * @inform: Structure containing potential arguments.
 * Return: Always 0
 */
int _micd(info_t *inform)
{
	char *x, *dr, buffer[1024];
	int chardr_rt;

	s = getcwd(buffer, 1024);
	if (!x)
		_puttss("TODO: >>getcwd failure emsg here<<\n");
	if (!inform->argv[1])
	{
		dr = _getemi(inform, "HOME=");
		if (!dr)
			chardr_rt = /* TODO: what should this be? */
				chardr((dr = _getemi(inform, "PWD=")) ? dr : "/");
		else
			chardr_ret = chdir(dr);
	}
	else if (_strngcmp(inform->argv[1], "-") == 0)
	{
		if (!_getemi(inform, "OLDPWD="))
		{
			_puttss(x);
			_putchar('\n');
			return (1);
		}
		_puttss(_getemi(inform, "OLDPWD=")), _putchar('\n');
		chardr_ret = /* TODO: what should this be? */
			chdir((dir = _getemi(inform, "OLDPWD=")) ? dr : "/");
	}
	else
		chardr_ret = chdir(inform->argv[1]);
	if (chardr_ret == -1)
	{
		display_err(inform, "can't cd to ");
		_eputs(inform->argv[1]), _eputchar('\n');
	}
	else
	{
		_setemi(inform, "OLDPWD", _getemi(inform, "PWD="));
		_setemi(inform, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _mihelp - changes the current directory of the process
 * @inform: Structure containing potential arguments.
 * Return: Always 0
 */
int _mihelp(info_t *inform)
{
	char **arg_arr;

	arg_arr = inform->argv;
	_puttss("help call works. Function not yet implemented \n");
	if (0)
		_puttss(*arg_arr); /* temp att_unused workaround */
	return (0);
}
