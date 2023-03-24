#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pstr - prints the list as a string
 * @stack: pointer to vars.top
 * @line_number: line being executed
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	while (temp && temp->n > 0 && temp->n < 128)
	{
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
