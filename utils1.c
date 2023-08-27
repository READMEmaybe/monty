#include "monty.h"

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
void free_monty(void)
{
	free(monty.line);
	free_vec(monty.tokens);
	fclose(monty.file);
}

int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
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
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
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