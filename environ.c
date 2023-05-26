#include "shell.h"

/**
 * _mienv - prints the current environment
 * @inform: Structure containing potential arguments.
 * Return: Always 0
 */
int _mienv(info_t *inform)
{
	display_list_string(inform->env);
	return (0);
}
/**
 * _getemi - gets the value of an environ variable
 * @inform: Structure containing potential arguments. Used to maintain
 * @name: emi var name
 * Return: the value
 */
char *_getemi(info_t *inform, const char *name)
{
	list_t *nd = info->emi;
	char *d;

	while (nd)
	{
		d = starts_plus(nd->str, name);
		if (d && *d)
			return (d);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * _misetemi - Initialize or modify an environment variable.
 * @inform: Structure containing potential arguments.
 *  Return: Always 0
 */
int _misetemi(info_t *inform)
{
	if (inform->argc != 3)
	{
		_eputtss("Incorrect number of arguements\n");
		return (1);
	}
	if (_setemi(inform, inform->argv[1], inform->argv[2]))
		return (0);
	return (1);
}

/**
 * _miunsetemi - Remove an environment variable
 * @inform: Structure containing potential arguments.
 * Return: Always 0
 */
int _miunsetemi(info_t *inform)
{
	int h;

	if (inform->argc == 1)
	{
		_eputtss("Too few arguements.\n");
		return (1);
	}
	for (h = 1; h <= inform->argc; h++)
		_unsetemi(inform, inform->argv[h]);

	return (0);
}
/**
 * populate_emi_list - populates emi linked list
 * @inform: Structure containing potential arguments.
 * Return: Always 0
 */
int populate_emi_list(info_t *inform)
{
	list_t *nd = NULL;
	size_t h;

	for (h = 0; emission[h]; h++)
		add_node_last(&nd, emission[i], 0);
	inform->emi = nd;
	return (0);
}
