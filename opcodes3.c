#include "monty.h"

/**
 * stack - Sets the mode of the data structure to stack (LIFO).
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script (unused).
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * queue - Sets the mode of the data structure to queue (FIFO).
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The current line number in the Monty script (unused).
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
