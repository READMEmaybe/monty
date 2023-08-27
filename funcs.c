#include "monty.h"

/**
 * push - Pushes an integer onto the top of a stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i, n;

	if (monty.tokens[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	for (i = 0; monty.tokens[1][i]; i++)
	{
		if (monty.tokens[1][i] == '-' && i == 0)
			continue;
		if (monty.tokens[1][i] < '0' || monty.tokens[1][i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(stack);
			free_monty();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(monty.tokens[1]);

	if (check_mode(*stack) == STACK)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}

/**
 * pall - Prints all the integers in the stack, starting from the top.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script (unused).
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;
	(void)line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
}


/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
