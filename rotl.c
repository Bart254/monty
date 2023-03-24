#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rotl - rotates the list, the first becomes last
 * @stack: pointer to vars.top
 * @line_number: line being executed
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp = (*stack)->next;
	temp->prev = NULL;
	(*stack)->next = NULL;
	*stack = temp;
}
