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
 * div_ - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void div_(stack_t **stack, unsigned int line_number)
{
	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
