#include "monty.h"

monty_t monty;

int main(int argc, char **argv)
{
    unsigned int line_number = 0;
    size_t size = 0;
    stack_t *stack = NULL;
    void (*func)(stack_t**, unsigned int);

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
    }
    monty.file = fopen(argv[1], "r");
    if (!monty.file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }    
	if (create_stack(&stack) == EXIT_FAILURE)
	{
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
    while (getline(&monty.line, &size, monty.file) != -1)
    {
		if (monty.tokens)
			free_vec(monty.tokens);
        line_number++;
        parse(&monty.tokens, monty.line, size, DELIMITERS);
		if (*monty.tokens == NULL)
			if (is_empty_line(monty.line, DELIMITERS))
				continue;
		if (monty.tokens[0][0] == '#')
			continue;
        func = get_func(monty.tokens[0]);
        if (!func)
        {
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, monty.tokens[0]);
			free_stack(&stack);
			free_monty();
			exit(EXIT_FAILURE);
		}
        func(&stack, line_number);
    }
	free_stack(&stack);
	free_monty();
	return(EXIT_SUCCESS);
}
