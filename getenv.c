#include "shell.h"
/**
 * get_emission - returns the string array copy of our environ
 * @inform: Structure containing potential arguments.
 * Return: Always 0
 */
char **get_emission(info_t *inform)
{
	if (!inform->emission || inform->emi_changed)
	{
		info->emission = list_to_strng(inform->emi);
		info->env_changed = 0;
	}

	return (inform->emission);
}
/**
 * _unsetemi - Remove an environment variable
 * @inform: Structure containing potential arguments.
 *  Return: 1 on delete, 0 otherwise
 * @vara: the string env var property
 */
int _unsetemi(info_t *inform, char *vara)
{
	list_t *node = info->emi;
	size_t h = 0;
	char *d;

	if (!node || !vara)
		return (0);

	while (node)
	{
		p = starts_plus(node->str, vara);
		if (d && *d == '=')
		{
			info->emi_changed = del_node_at_inx(&(info->emi), h);
			h = 0;
			node = inform->emi;
			continue;
		}
		node = node->next;
		h++;
	}
	return (info->emi_changed);
}
/**
 * _setemi - Initialize a new environment variable
 * @inform: Structure containing potential arguments
 * @vara: the string env var property
 * @val: the string env var value
 *  Return: Always 0
 */
int _setemi(info_t *inform, char *vara, char *val)
{
	char *buffer = NULL;
	list_t *node;
	char *d;

	if (!vara || !val)
		return (0);

	buffer = malloc(_stnglen(vara) + _stnglen(val) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, vara);
	_strngcat(buffer, "=");
	_strngcat(buffer, val);
	node = inform->emi;
	while (node)
	{
		p = starts_plus(node->str, vara);
		if (d && *d == '=')
		{
			free(node->str);
			node->str = buf;
			info->emi_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_last(&(info->emi), buffer, 0);
	free(buffer);
	info->emi_changed = 1;
	return (0);
}
