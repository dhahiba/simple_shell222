#include "shell.h"
/**
 * _strcmp - Compares pointers to two strings
 * @s1: string
 * @s2: String
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * strwith - ...
 * @ch1: string
 * @ch2: string
 * Return: string
 */
char *strwith(const char *ch1, const char *ch2)
{
while (*ch2)
{
if (*ch1 != *ch2)
return (NULL);
ch1++;
ch2++;
}
return ((char *)ch1);
}
/**
 * _strcat - Concatenates two strings
 * @dest: String
 * @src: String
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
int dlen = 0, i;

while (dest[dlen])
dlen++;
for (i = 0; src[i] != 0; i++)
{
dest[dlen] = src[i];
dlen++;
}
dest[dlen] = '\0';
return (dest);
}
/**
 * _strncpy - Copies at most an inputted number
 * @dest: String
 * @src: String
 * @n: integer
 * Return: String
 */
char *_strncpy(char *dest, char *src, int n)
{
	int index = 0, src_len = 0;

	while (src[index++])
		src_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[index] = src[index];
	for (index = src_len; index < n; index++)
		dest[index] = '\0';
	return (dest);
}
/**
 * _strncat - Concatenates two strings
 * @dest: String
 * @src: String
 * @n: The number of bytes
 * Return: String
 */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[dest_len++] = src[index];
	return (dest);
}
