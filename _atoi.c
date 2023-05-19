#include "shell.h"

/**
 * interact - returns true if shell is interactive mode
 * @inform: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interact(info_t *inform)
{
	return (isatty(STDIN_FILENO) && inform->readfd <= 2);
}

/**
 * is_del - checks if character is a delimeter
 * @x: the char to check
 * @del: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_del(char x, char *del)
{
	while (*del)
		if (*del++ == x)
			return (1);
	return (0);
}

/**
 * _isalp - checks for alphabetic character
 * @x: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalp(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoinie - converts a string to an integer
 * @b: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoinie(char *b)
{
	int y, mark = 1, pole = 0, outp;
	unsigned int ans = 0;

	for (y = 0; b[y] != '\0' && pole != 2; y++)
	{
		if (b[y] == '-')
			mark *= -1;

		if (b[y] >= '0' && b[y] <= '9')
		{
			pole = 1;
			ans *= 10;
			ans += (s[i] - '0');
		}
		else if (pole == 1)
			pole = 2;
	}

	if (mark == -1)
		outp = -ans;
	else
		outp = ans;

	return (outp);
}
