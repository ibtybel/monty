#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(utls.file_ptr);
		free(utls.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(utls.file_ptr);
		free(utls.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int n;

	(void)line_number;
	tmp = *stack;
	while (tmp)
	{
		n = tmp->n;
		if (n <= 0 || n > 127)
			break;
		printf("%c", n);
		tmp = tmp->next;
	}
	printf("\n");
}
