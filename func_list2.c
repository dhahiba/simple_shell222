#include "shell.h"
/**
 * list_len - ...
 * @h: ...
 * Return: ...
 */
size_t list_len(const link_l *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
/**
 * list_to_string - ...
 * @h: ...
 * Return: ...
 */
char **list_to_string(link_l *h)
{
char *s;
char **ss;
link_l *n = h;
size_t i, j;

i = list_len(h);
if (!h || !i)
return (NULL);
ss = malloc(sizeof(char *) * (i + 1));
if (!ss)
return (NULL);
i = 0;
while (n)
{
s = malloc(_strlen(n->s) + 1);
if (!s)
{
for (j = 0; j < i; j++)
free(ss[j]);
free(ss);
return (NULL);
}
s = _strcpy(s, n->s);
ss[i] =s;
n = n->next;
i++;
}
ss[i] = NULL;
return (ss);
}
/**
 * print_listint - ...
 * @h: ...
 * Return: ...
 */
size_t print_listint(const link_l *h)
{
size_t s = 0;

	while (h)
	{
	_puts(convert_number(h->n, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(h->s ? h->s : "(nil)");
	_puts("\n");
	h = h->next;
	s++;
	}
	return (s);
}
/**
 * node_starts_with - ...
 * @node: ...
 * @pr: ...
 * @c: ...
 * Return: ...
 */
link_l *node_starts_with(link_l *node, char *pr, char c)
{
char *p = NULL;
while (node)
{
p = strwith(node->s, pr);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
 * get_node_index - ...
 * @h: ...
 * @n: ...
 * Return: ...
 */
ssize_t get_node_index(link_l *h, link_l *n)
{
	size_t i = 0;

	while (h)
	{
		if (h == n)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}
