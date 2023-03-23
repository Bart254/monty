#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * execute - executes the monty command
 * @opcode: passed command
 * @line_number: line being executed
 */
void execute(char *opcode, unsigned int line_number)
{
	instruction_t func[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"add", add}, {"sub", sub},
		{"div", _div}, {"mul", mul}, {"mod", mod}, {"nop", nop},
		{"swap", swap}, {NULL, NULL}};
	int e = 0;

	if (opcode == NULL)
		return;
	while (func[e].opcode != NULL)
	{
		if (opcode[0] == '#')
		{
			nop(&vars.top, line_number);
			return;
		}
		if (strcmp(opcode, func[e].opcode) == 0)
		{
			func[e].f(&vars.top, line_number);
			return;
		}
		e++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	_free();
	exit(EXIT_FAILURE);
}
