#include <stdio.h>
#include "monty.h"
/**
 * pall - prints all elements of the stack
 * @stack: top element in the stack
 * @line_number: line being executed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *start = *stack;

	(void)line_number;
	while (start)
	{
		fprintf(stdout, "%d\n", (start)->n);
		start = start->next;
	}
}

