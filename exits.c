#include "shell.h"

/**
 * _strngcpy - copies a string
 * @dxt: the destination string to be copied to
 * @sorc: the source string
 * @u: the amount of characters to be copied
 * Return: the concatenated string
 */
char *_strngcpy(char *dxt, char *sorc, int u)
{
	int h, l;
	char *es = dxt;

	h = 0;
	while (sorc[h] != '\0' && h < u - 1)
	{
		dxt[h] = sorc[h];
		h++;
	}
	if (h < u)
	{
		l = h;
		while (l < u)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (es);
}
/**
 * _strngcat - concatenates two strings
 * @dxt: the first string
 * @sorc: the second string
 * @u: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_strngcat(char *dxt, char *sorc, int u)
{
	int h, l;
	char *es = dest;

	h = 0;
	l = 0;
	while (dest[h] != '\0')
		h++;
	while (sorc[l] != '\0' && l < u)
	{
		dest[h] = src[l];
		h++;
		l++;
	}
	if (l < u)
		dxt[h] = '\0';
	return (es);
}

/**
 * _strcat - locates a character in a string
 * @x: the string to be parsed
 * @se: the character to look for
 * Return: (x) a pointer to the memory area s
 */
char *_strcat(char *x, char se)
{
	do {
		if (*x == se)
			return (x);
	} while (*x++ != '\0');

	return (NULL);
}

