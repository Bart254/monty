#include <stdlib.h>
#include "monty.h"
#include <string.h>

/**
 * push - adds a new node to stack
 * @stack: vars.top of the stack
 * @line_number: line being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int number;

	(void)stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_err_message();
	if (vars.number)
	{
		number = atoi(vars.number);
		if (number == 0 && (strcmp(vars.number, "0") != 0 ||
				strcmp(vars.number, "-0") != 0))
		{
			_free();
			push_err_message(line_number);
		}
	}
	else
	{
		_free();
		push_err_message(line_number);
	}
	new->n = number;
	new->next = vars.top;
	new->prev = NULL;
	if (vars.top != NULL)
		vars.top->prev = new;
	vars.top = new;
}
