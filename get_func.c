#include "monty.h"

void (*get_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; funcs[i].opcode; i++)
	{
		if (strcmp(opcode, funcs[i].opcode) == 0)
			return (funcs[i].f);
	}

	return (NULL);
}