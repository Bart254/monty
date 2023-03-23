#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - prints the top element of the stack
 * @stack: pointer to head
 * @line_number: line being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		fprintf(stdout, "%d\n", (*stack)->n);
	else
	{
		_free();
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
