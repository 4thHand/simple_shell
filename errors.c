#include "shell.h"

/**
 * _eputtss - prints an input string
 * @strng: the string to be printed
 * Return: Nothing
 */
void _eputtss(char *strng)
{
	int x = 0;

	if (!strng)
		return;
	while (strng[x] != '\0')
	{
		_eputchar(strng[x]);
		x++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @x: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char x)
{
	static int h;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || h >= WRITE_BUF_SIZE)
	{
		write(2, buf, h);
		h = 0;
	}
	if (x != BUF_FLUSH)
		buf[x++] = x;
	return (1);
}

/**
 * _putcd - writes the character c to given fd
 * @x: The character to print
 * @cd: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putcd(char x, int cd)
{
	static int h;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || h >= WRITE_BUF_SIZE)
	{
		write(cd, buf, h);
		h = 0;
	}
	if (x != BUF_FLUSH)
		buf[h++] = x;
	return (1);
}

/**
 * _putscd - prints an input string
 * @strng: the string to be printed
 * @cd: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putscd(char *strng, int cd)
{
	int h = 0;

	if (!strng)
		return (0);
	while (*strng)
	{
		h += _putcd(*strng++, cd);
	}
	return (h);
}
