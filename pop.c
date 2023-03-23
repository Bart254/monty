#include <stdlib.h>
#include "monty.h"
#include <stdio.h>

/**
 * pop - removes the top element
 * @stack: pointer to head
 * @line_number: line being executed
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		_free();
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
