#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: previous element
 * @next: next element
 *
 * Description: doubly linked list node structure
 * for stacks, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stacks, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_v - global variables
 * @top: top of stack/queue
 * @number: number to be pushed to stack/queue
 * @full_command: command passed to file
 * @stream: monty file with monty commands
 */
typedef struct global_v
{
	stack_t *top;
	char *number;
	char *full_command;
	FILE *stream;
} global_t;
void open_err_message(char *filename);
char *get_opcode(char *full_command);
void execute(char *opcode, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push_err_message(int line_number);
void malloc_err_message(void);
void _free(void);
extern global_t vars;

#endif /* monty.h */
