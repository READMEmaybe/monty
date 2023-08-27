#include "monty.h"

/**
 * start_monty - Initializes the Monty interpreter.
 * @argc: The number of command line arguments.
 * @filename: The name of the Monty script file to be opened.
 * @stack: A pointer to the pointer that will store the created stack.
 *
 * Return: EXIT_SUCCESS if the Monty interpreter is successfully initialized,
 *          or EXIT_FAILURE if any step fails.
 */
int start_monty(int argc, const char *filename, stack_t **stack)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	monty.file = fopen(filename, "r");
	if (!monty.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	if (create_stack(stack) == EXIT_FAILURE)
	{
		fclose(monty.file);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * create_stack - Creates an empty stack.
 * @stack: A pointer to the pointer that will store the created stack.
 *
 * Return: EXIT_SUCCESS if the stack is successfully created, or EXIT_FAILURE
 *          if memory allocation fails.
 */
int create_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
	}

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks the current mode of the data structure.
 * @stack: A pointer to the stack data structure.
 *
 * Return: An integer indicating the mode: STACK, QUEUE,
 *	or 2 for undefined/invalid.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * free_stack - Frees a stack and its nodes.
 * @stack: A pointer to the pointer to the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * free_monty - Frees resources used by the Monty interpreter.
 */
void free_monty(void)
{
	free(monty.line);
	free_vec(monty.tokens);
	fclose(monty.file);
}
