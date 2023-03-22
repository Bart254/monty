#include <stdio.h>
#include <stdlib.h>

/**
 * push_err_message - displays an error message
 * @line_number: line containing the error
 */
void push_err_message(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * open_err_message - displays an error message when a file can't be opened
 * @filename: name of the file
 */
void open_err_message(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * malloc_err_message - displays a message if malloc fails
 */
void malloc_err_message(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
