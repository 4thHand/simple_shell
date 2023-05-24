#include "shell.h"
/**
 * clear_inf - initializes info_t struct
 * @inform: struct address
 */
void clear_inf(info_t *inform)
{
	inform->argu = NULL;
	inform->argv = NULL;
	inform->way = NULL;
	inform->argc = 0;
}

/**
 * place_inf - initializes info_t struct
 * @inform: struct address
 * @av: argument vector
 */
void place_inf(info_t *inform, char **av)
{
	int i = 0;

	inform->fname = av[0];
	if (inform->argu)
	{
		inform->argv = strtow(inform->arg, " \t");
		if (!inform->argv)
		{
			inform->argv = malloc(sizeof(char *) * 2);
			if (inform->argv)
			{
				inform->argv[0] = _strdupp(inform->argu);
				inform->argv[1] = NULL;
			}
		}
		for (i = 0; inform->argv && inform->argv[i]; i++)
			;
		inform->argc = i;

		sub_alias(inform);
		sub_vars(inform);
	}
}
/**
 * free_inf - frees info_t struct fields
 * @inform: struct address
 * @ally: true if freeing all fields
 */
void free_inf(info_t *inform, int ally)
{
	ffree(inform->argv);
	inform->argv = NULL;
	inform->path = NULL;
	if (ally)
	{
		if (!inform->cmd_buf)
			free(inform->argu);
		if (inform->emi)
			free_list(&(info->emi));
		if (inform->history)
			free_list(&(info->history));
		if (inform->a_node)
			free_list(&(info->a_node));
		ffree(inform->environ);
			inform->emission = NULL;
		bfree((void **)inform->cmd_buffer);
		if (inform->rdfd > 2)
			close(inform->rdfd);
		_putchar(BUF_FLUSH);
	}
}
