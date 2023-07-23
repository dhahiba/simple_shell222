#include "shell.h"
/**
 * add_node - ...
 * @head: ...
 * @str: ..
 * @n: ...
 * Return: ...
 */
link_l *add_node(link_l **head, const char *str, int n)
{
	link_l *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(link_l));
	if (!new)
		return (NULL);
	new->n = n;
	new->s = _strdup(str);
	new->next = (*head);
	(*head) = new;
	return (*head);
}
/**
 * add_node_end - ...
 * @head: ...
 * @str: ...
 * @n: int
 * Return: ...
 */
link_l *add_node_end(link_l **head, const char *str, int n)
{
	link_l *new;
	link_l *temp = *head;

	if (!head)
		return (NULL);
	new = malloc(sizeof(link_l));
	if (!new)
		return (NULL);

	new->s = _strdup(str);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (new);
}
/**
 * print_list_str - ...
 * @h: ...
 * Return: ...
 */
size_t print_list_str(const link_l *h)
{
	size_t s = 0;

	while (h)
	{
	if (!h->s)
		printf("[0] (nil)\n");
	else
		printf(" %s\n", h->s);
	h = h->next;
	s++;
	}
	return (s);
}
/**
 * delete_node_at_index - ....
 * @head: ...
 * @index: ...
 * Return: ....
 */
int delete_node_at_index(link_l **head, unsigned int index)
{
	link_l *node, *prev;
	unsigned int i = 0;

	if (!head || !*head)
	return (0);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->s);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev->next = node->next;
			free(node->s);
			free(node);
			return (1);
		}
		i++;
		prev = node;
		node = node->next;
	}
	return (0);
}
/**
 * free_list - ...
 * @head: ...
 * Return: ...
 */
void free_list(link_l *head)
{
	link_l *temp;

	while (head)
	{
		temp = head->next;
		free(head->s);
		free(head);
		head = temp;
	}
}
