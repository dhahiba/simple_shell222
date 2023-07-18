#include "shell.h"
/**
 * _strchr - ..
 * @s: ..
 * @ch: ...
 * Return: ...
 */
char *_strchr(const char *s, int ch)
{

while (*s != '\0')
{
if (*s == ch)
return ((char *)s);
s++;
}

if (*s == ch)
return ((char *)s);

return (NULL);
}

