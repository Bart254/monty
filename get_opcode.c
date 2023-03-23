#include <unistd.h>
#include <stdio.h>
#include "monty.h"
#include <string.h>

/**
 * get_opcode - gets code the from a file
 * @full_command: file stream command
 *
 * The function gets the stack/queue command passed into a file
 * and return the command to the main function after making
 * necessary modifications like removing white spaces
 * Return: pointer to the command
 */
char *get_opcode(char *full_command)
{
	char *code, *token;

	code = strtok(full_command, " \t\n");
	if (code)
		vars.number = strtok(NULL, " \t\n");
	else
		vars.number = NULL;
	token = vars.number;
	while (token)
		token = strtok(NULL, " \t\n");
	return (code);
}
