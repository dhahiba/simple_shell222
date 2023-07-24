#include "shell0.h"
/**
 * ffree - ..
 * @p: ...
 */
void ffree(char **p)
{
if (p == NULL)
return;

for (int i = 0; p[i] != NULL; i++)
{
free(p[i]);
}
free(p);
}
/**
 * *_realloc - ...
 * @ptr: ...
 * @old_size: ...
 * @new_size: ...
 * Return: ...
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		for (i = 0; i < old_size && i < new_size; i++)
			*((char *)p + 1) = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
/**
 * _memset - fills memory with a constant byte
 * @s: starting address of memory to be filled
 * @b: the desired value
 * @n: unsigned int
 * Return: changed array with new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
/**
 * bfree - ..
 * @p: ..
 * Return: ...
 */
int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (-1);
}
