#include "monty.h"

/**
 * rotl_ - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number
 */

void rotl_(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	tmp2 = (*stack)->next;
	tmp2->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	(*stack)->next = NULL;
	*stack = tmp2;
}

/**
 * rotr_ - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number
 */

void rotr_(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = tmp->prev;
	tmp2->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
