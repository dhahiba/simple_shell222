#include "shell.h"
/**
 * list_len - ...
 * @h: ...
 * Return: ...
 */
size_t list_len(const list_t *h)
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
char  *list_to_string(const listint_t *h)
{
size_t lines = list_len(head);
int i = 0;
struct _node *curr = head;

char *textBufferArray = NULL;
textBufferArray = malloc(charCount(head) + lines + 1);

if (lines > 0)
{
while (curr->next != NULL)
{
strlcpy(textBufferArray[i], curr->text, strlen(curr->text) + 1);
curr = curr->next;
i++;
}
}
textBufferArray[charCount(head) + lines] = '\0';
return (textBufferArray);
}
/**
 * print_listint - ...
 * @h: ...
 * Return: ...
 */
size_t print_listint(const listint_t *h)
{
size_t s = 0;

	while (h)
	{
	_puts(convert_number(h->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(h->str ? h->str : "(nil)");
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
list_t *node_starts_with(list_t *node, char *pr, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, pr);
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
ssize_t get_node_index(list_t *h, list_t *n)
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
