#include "shell.h"

/**
 * list_lenht - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_lenht(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * list_to_strng - returns an array of strings of the list->str
 * @top: pointer to first node
 * Return: array of strings
 */
char **list_to_strng(list_t *top)
{
	list_t *node = top;
	size_t i = list_len(top), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * display_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t display_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puttss(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puttss(h->str ? h->str : "(nil)");
		_puttss("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_str_as - returns node whose string starts with prefix
 * @node: pointer to list head
 * @pre: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_str_as(list_t *node, char *pre, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_plus(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_inx - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_inx(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

