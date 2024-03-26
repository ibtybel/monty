#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define BUFFSIZE 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct utils_s - struct to hold global variables
 * @args: array of strings to hold opcode and argument
 * @line_n: line number of the file
 * @file_ptr: pointer to the file
 * @queue: flag to indicate if queue is enabled
 * Description: struct to hold global variables
 * for stack, queues, LIFO, FIFO
 */

typedef struct utils_s
{
	char **args;
	unsigned int line_n;
	FILE *file_ptr;
	int queue;
} utils_t;

extern utils_t utls;

void parse_line(char *line, stack_t **stack);
void add_node(stack_t **stack, const int n);
void add_node_end(stack_t **stack, const int n);
void push_(stack_t **stack, unsigned int line_number);
void pall_(stack_t **stack, unsigned int line_number);
void pint_(stack_t **stack, unsigned int line_number);
void pop_(stack_t **stack, unsigned int line_number);
void swap_(stack_t **stack, unsigned int line_number);
void add_(stack_t **stack, unsigned int line_number);
void nop_(stack_t **stack, unsigned int line_number);
void sub_(stack_t **stack, unsigned int line_number);
void div_(stack_t **stack, unsigned int line_number);
void mul_(stack_t **stack, unsigned int line_number);
void mod_(stack_t **stack, unsigned int line_number);
void pchar_(stack_t **stack, unsigned int line_number);
void pstr_(stack_t **stack, unsigned int line_number);
void rotl_(stack_t **stack, unsigned int line_number);
void rotr_(stack_t **stack, unsigned int line_number);
void stack_queue(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);

#endif
