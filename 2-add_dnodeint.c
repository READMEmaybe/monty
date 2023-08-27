#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * of a dlistint_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new, *h, *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	h = *head;

	tmp = h->next;
	new->prev = h;
	new->next = tmp;
	if (tmp)
		tmp->prev = new;
	h->next = new;

	return (new);
}
