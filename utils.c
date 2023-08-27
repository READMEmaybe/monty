#include "monty.h"

/**
 * free_vec - Frees a dynamically allocated string vector and its contents.
 * @vec: A pointer to the dynamically allocated string vector.
 */
void free_vec(char **vec)
{
	int i;

	if (vec)
	{
		for (i = 0; vec[i]; i++)
			free(vec[i]);
		free(vec);
		vec = NULL;
	}
}
/**
 * is_empty_line - Checks if a line consists only of delimiters.
 * @line: The string to be checked.
 * @delims: The string of delimiter characters.
 *
 * Return: 1 if the line consists only of delimiters, 0 otherwise.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

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
