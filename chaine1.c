#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}
/**
 * _strdup - ...
 * @str: string
 * Return: .....
 */
char *_strdup(const char *str)
{
if (str == NULL)
return (NULL);

size_t length = strlen(str);
char *ret = malloc(length + 1);

if (ret == NULL)
return (NULL);

_strcpy(ret, str);
return (ret);
}
/**
 * _strcpy - copy a string
 * @dest: destination value
 * @src: source value
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}
/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: on success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * _puts -prints a string, followed by a new line, to stdout
 * @str: string to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
