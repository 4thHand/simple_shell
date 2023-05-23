#include "shell.h"

/**
 * _erratoinie - converts a string to an integer
 * @c: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
int _erratoinie(char *c)
{
	int h = 0;
	unsigned long int ans = 0;

	if (*c == '+')
		c++;  /* TODO: why does this make main return 255? */
	for (h = 0;  c[h] != '\0'; h++)
	{
		if (c[h] >= '0' && c[h] <= '9')
		{
			ans *= 10;
			ans += (c[h] - '0');
			if (ans INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (ans);
}

/**
 * display_err - prints an error message
 * @inform: the parameter & return info struct
 * @estrrs: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void display_err(info_t *inform, char *estrrs)
{
	_eputtss(inform->fname);
	_eputtss(": ");
	display_d(inform->line_count, STDERR_FILENO);
	_eputtss(": ");
	_eputtss(inform->argv[0]);
	_eputtss(": ");
	_eputtss(estrrs);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @inp: the input
 * @cd: the filedescriptor to write to
 * Return: number of characters printed
 */
int print_d(int inp, int cd)
{
	int (*__putchar)(char) = _putchar;
	int h, countin = 0;
	unsigned int _albs_, currently;

	if (cd == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_albs_ = -inp;
		__putchar('-');
		countin++;
	}
	else
		_albs_ = inp;
	currently = _albs_;
	for (h = 1000000000; h > 1; h /= 10)
	{
		if (_albs_ / h)
		{
			__putchar('0' + currently / h);
			countin++;
		}
		currently %= i;
	}
	__putchar('0' + currently);
	countly++;

	return (countly);
}

/**
 * conv_numb - converter function, a clone of itoa
 * @numb: number
 * @start: base
 * @warning: argument flags
 * Return: string
 */
char *conv_numb(long int numb, int start, int warning)
{
	static char *arr;
	static char buff[50];
	char mark = 0;
	char *point;
	unsigned long h = numb;

	if (!(mark & CONVERT_UNSIGNED) && numb < 0)
	{
		h = -numb;
		mark = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	point = &buff[49];
	*point = '\0';

	do	{
		*--point = array[h % start];
		h /= start;
	} while (h != 0);

	if (mark)
		*--point = mark;
	return (point);
}
/**
 * remv_comt - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 * Return: Always 0;
 */
void remv_comt(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
}
