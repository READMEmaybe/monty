#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp;

	tmp = (*stack)->next;
	for (; tmp != NULL; tmp = tmp->next, len++)
		;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * nop - As useful as I am
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the top element from the second element of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp;

	tmp = (*stack)->next;
	for (; tmp != NULL; tmp = tmp->next, len++)
		;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * div_ - Divides the second element by the top element of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void div_(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp;

	tmp = (*stack)->next;
	for (; tmp != NULL; tmp = tmp->next, len++)
		;
	if (len < 2 || (*stack)->next->n == 0)
	{
		fprintf(stderr, len < 2 ? "L%u: can't div, stack too short\n"
		: "L%u: division by zero\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp;

	tmp = (*stack)->next;
	for (; tmp != NULL; tmp = tmp->next, len++)
		;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}
