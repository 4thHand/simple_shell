#include "shell.h"
/**
 *  hxh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hxh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puttss("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_makein(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_inf(info, 0);
	}
	enter_history(info);
	free_inf(info, 1);
	if (!interactive(info) && info->stat)
		exit(info->stat);
	if (builtin_ret == -2)
	{
		if (info->er_numb == -1)
			exit(info->stat);
		exit(info->er_numb);
	}
	return (builtin_ret);
}

/**
 * find_makein - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *	0 if builtin executed successfully,
 *	1 if builtin found but not successful,
 *	2 if builtin signals exit()
 */
int find_makein(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _miex},
		{"env", _miemi},
		{"help", _mihelp},
		{"history", _mihistory},
		{"setenv", _misetemi},
		{"unsetenv", _miunsetemi},
		{"cd", _micd},
		{"alias", _mialias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strngcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *way = NULL;
	int i, k;

	info->way = info->argv[0];
	if (info->ercount_put == 1)
	{
		info->er_count++;
		info->ercount_put = 0;
	}
	for (i = 0, k = 0; info->argu[i]; i++)
		if (!is_del(info->argu[i], " \t\n"))
			k++;
	if (!k)
		return;

	way = find_way(info, _getemi(info, "PATH="), info->argv[0]);
	if (way)
	{
		info->way = way;
		frk_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getemi(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			frk_cmd(info);
		else if (*(info->argu) != '\n')
		{
			info->stat = 127;
			display_err(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void frk_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->way, info->argv, get_emiron(info)) == -1)
		{
			free_inf(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}

		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->stat));
		if (WIFEXITED(info->stat))
		{
			info->stat = WEXITSTATUS(info->stat);
			if (info->stat == 126)
				display_err(info, "Permission denied\n");
		}
	}
}
