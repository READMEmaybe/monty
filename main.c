#include "monty.h"

char **tokens = NULL;

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
    if (!bytecode_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }    
	if (create_stack(&stack) == EXIT_FAILURE)
	{
		fclose(bytecode_file);
		return (EXIT_FAILURE);
	}
    while (getline(&lineptr, &size, bytecode_file) != -1)
    {
        line_number++;
        parse(&tokens, lineptr, size, DELIMITERS);
		if (tokens == NULL)
		{
			if (is_empty_line(lineptr, DELIMITERS))
				continue;
		}
		if (tokens[0][0] == '#')
		{
			free_tokens();
			continue;
		}
        func = get_func(tokens[0]);
        if (!func)
        {
			free_stack(&stack);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tokens[0]);
			free_tokens();
			return(EXIT_FAILURE);
		}
        func(&stack, line_number);
        free_tokens();
    }
	free_stack(&stack);
	fclose(bytecode_file);
	return(code);
}
