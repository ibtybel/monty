#include "monty.h"

/**
 * sub_ - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack
 * @line_number: line number
*/

void sub_(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(utls.file_ptr);
		free(utls.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop_(stack, line_number);
	(*stack)->n -= n;
}

/**
 * div_ - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @line_number: line number
*/

void div_(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(utls.file_ptr);
		free(utls.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(utls.file_ptr);
		free(utls.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	pop_(stack, line_number);
	(*stack)->n /= n;
}
