#include "monty.h"

/**
 * mod - Computes the modulo of the second element
 *	by the top element of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *tmp;

	tmp = (*stack)->next;
	for (; tmp != NULL; tmp = tmp->next, len++)
		;
	if (len < 2 || (*stack)->next->n == 0)
	{
		fprintf(stderr, len < 2 ? "L%u: can't mod, stack too short\n"
		: "L%u: division by zero\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!((*stack)->next) || (*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, !((*stack)->next) ? "L%u: can't pchar, stack empty\n"
		: "L%u: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		free_monty();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}


/**
 * rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}