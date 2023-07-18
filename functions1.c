#include "shell.h"
/**
 * _inter - ...
 * @f: ..
 * Return: ...
 */
int _inter(info_t *f)
{
	if (isatty(STDIN_FILENO) && f->readfd <= 2)
		return (true);
	else
		return (false);
}
/**
 * is_delim - ...
 * @c: ...
 * @d: ...
 * Return: ...
 */
int is_delim(char c, char *d)
{
	while (*d)
	{
		if (*d == c)
			return (1);
		*d++;
	}
	return (0);
}
/**
 * _isalpha - Checks for alphabeic character
 * @c: The character to be checked
 * Return: 1 for alphabetic character or 0 for anything else
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
/**
 * print_error - ...
 * @f: ...
 * @s: ...
 *
 * Return: ..
 */
void print_error(info_t f, char *s)
{
	_puts(f->fname);
	_putchar(' ');
	print_d(f->line_count, STDERR_FILENO);
	_putchar(':');
	_putchar(' ');
	_puts(f->argv[0]);
	_putchar(':');
        _putchar(' ');
	_puts(s);
}
