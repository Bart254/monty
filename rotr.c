#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * rotr - last element becomes the first
 * @stack: pointer to vars.top
 * @line_number: line being executed
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (temp->next)
		temp = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	(temp->prev)->next = NULL;
	temp->prev = NULL;
	*stack = temp;
}
