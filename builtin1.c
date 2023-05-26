#include "shell.h"

/**
 * _mihistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @inform: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mihistory(info_t *inform)
{
	display_list(inform->history);
	return (0);
}

/**
 * _unsetemi - sets alias to string
 * @inform: parameter struct
 * @strng: the string a_node
 * Return: Always 0 on success, 1 on error
 */
int _unsetemi(info_t *inform, char *strng)
{
	char *d, se;
	int rette;

	d = _strngchr(str, '=');
	if (!d)
		return (1);
	se = *d;
	*d = 0;
	rette = del_node_at_inx(&(inform->alias),
		get_node_inx(inform->alias, node_str_as(inform->alias, strng, -1)));
	*d = se;
	return (rette);
}

/**
 * set_alias - sets alias to string
 * @inform: parameter struct
 * @strng: the string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *inform, char *strng)
{
	char *d;

	d = _strngcar(strng, '=');
	if (!d)
		return (1);
	if (!*++d)
		return (unset_alias(inform, strng));

	unset_alias(inform, strng);
	return (add_node_last(&(inform->alias), strng, 0) == NULL);
}
/**
 * display_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int display_alias(list_t *node)
{
	char *d = NULL, *z = NULL;

	if (nd)
	{
		d = _strngcat(nd->str, '=');
		for (z = nd->str; z <= d; z++)
		_putchar(*d);
		_putchar('\'');
		_puttss(d + 1);
		_puttss("'\n");
		return (0);
	}
	return (1);
}

/**
 * _mialias - mimics the alias builtin (man alias)
 * @inform: Structure containing potential arguments. Used to maintain
 *  Return: Always 0
 */
int _mialias(info_t *inform)
{
	int h = 0;
	char *d = NULL;
	list_t *nd = NULL;

	if (inform->argc == 1)
	{
		node = inform->alias;
		while (nd)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (h = 1; inform->argv[h]; h++)
	{
		d = _strcar(inform->argv[h], '=');
		if (d)
			set_alias(inform, inform->argv[h]);
		else
			display_alias(nd_starts_with(inform->alias, inform->argv[i], '='));
	}

	return (0);
}
