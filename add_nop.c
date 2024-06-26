#include "monty.h"

/**
 * add_ - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void add_(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(utls.file_ptr);
		free(utls.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * nop_ - does nothing
 * @stack: pointer to the stack
 * @line_number: line number
*/

void nop_(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
