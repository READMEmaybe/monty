#include "monty.h"

monty_t monty;

int main(int argc, char **argv)
{
    FILE *bytecode_file = NULL;
    char *lineptr = NULL;
    unsigned int line_number = 0;
    size_t size = 0, code = EXIT_SUCCESS;
    stack_t *stack = NULL;
    void (*func)(stack_t**, unsigned int);

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
    }
    bytecode_file = fopen(argv[1], "r");
	monty.file = bytecode_file;
    if (!bytecode_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }    
	if (create_stack(&stack) == EXIT_FAILURE)
	{
		fclose(bytecode_file);
		exit(EXIT_FAILURE);
	}
    while (getline(&lineptr, &size, bytecode_file) != -1)
    {
		if (monty.tokens)
			free_vec(monty.tokens);
        line_number++;
		monty.line = lineptr;
        parse(&monty.tokens, lineptr, size, DELIMITERS);
		if (*monty.tokens == NULL)
		{
			if (is_empty_line(lineptr, DELIMITERS))
				continue;
		}
		
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
	return(code);
}
