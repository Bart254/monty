#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

global_t vars;
/**
 * main - executes monty code
 * @ac: number of args passed
 * @av: args passed
 *
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	unsigned int line_number = 0;
	instruction_t monty;
	size_t n = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	vars.stream = fopen(av[1], "r");
	if (vars.stream == NULL)
		open_err_message(av[1]);
	vars.top = NULL;
	vars.full_command = NULL;
	while (getline(&(vars.full_command), &n, vars.stream) != EOF)
	{
		++line_number;
		monty.opcode = get_opcode(vars.full_command);
		execute(monty.opcode, line_number);
	}
	_free();
	return (0);
}
