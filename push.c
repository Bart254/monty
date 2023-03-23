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

	if (vars.number)
	{
		number = atoi(vars.number);
		if (number != 0)
			confirm(number, line_number);
		if (number == 0 && (strcmp(vars.number, "0") != 0 &&
				strcmp(vars.number, "-0") != 0))
			push_err_message(line_number);
	}
	else
		push_err_message(line_number);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_err_message();
	new->n = number;
	new->next = (*stack);
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}

/**
 * confirm - checks if argument passed is an actual number
 * @n: arg passed
 * @line_number: line being executed
 *
 * When we use atoi, errors in strings like 8hfghdh are undetectable
 * because such is converted to the first integer, 8
 * this function further tests if args passed are actually numbers
 * by detecting such errors
 */
void confirm(int n, unsigned int line_number)
{
	int e = 0, f = 0, l;
	char str[20], temp;

	if (n < 0)
	{
		str[0] = '-';
		e++;
		f++;
	}
	for (n = abs(n); n; e++, n /= 10)
		str[e] = n % 10 + '0';
	str[e] = '\0';
	for (l = e - 1; l > f; l--, f++)
	{
		temp = str[f];
		str[f] = str[l];
		str[l] = temp;
	}
	for (e = 0; vars.number[e]; e++)
	{
		if (str[e] != vars.number[e])
			push_err_message(line_number);
	}
}
