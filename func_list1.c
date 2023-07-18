#include "shell.h"
/**
 * add_node - ...
 * @head: ...
 * @str: ..
 * @n: ...
 * Return: ...
 */
list_t *add_node(list_t **head, const char *str, int n)
{
	list_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->num = n;
	new->str = _strdup(str);
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
list_t *add_node_end(list_t **head, const char *str, int n)
{
	list_t *new;
	list_t *temp = *head;

	if (!head)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = _strdup(str);
	new->num = n;
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
size_t print_list_str(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
	if (!h->str)
		printf("[0] (nil)\n");
	else
		printf(" %s\n", h->str);
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
int delete_node_at_index(listint_t **head, unsigned int index)
{
	listint_t *node, *prev;
	unsigned int i = 0;

	if (!head || !*head)
	return (0);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev->next = node->next;
			free(node->str);
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
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
