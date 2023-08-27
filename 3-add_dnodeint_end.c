#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end
 * of a stack_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *h, *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	h = *head;
	tmp = h;
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	new->next = NULL;
	tmp->next = new;

	return (new);
}
