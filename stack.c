#include "monty.h"

/**
 * stack - changes mode to stack
 * @stack: pointer to vars.top
 * @line_number: line being executed
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	vars.mode = "stack";
}
