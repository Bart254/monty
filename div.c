#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _div - divs the first two elements
 * @stack: pointer to vars.top
 * @line_number: line being executed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp->n /= (*stack)->n;
	pop(stack, line_number);
}
