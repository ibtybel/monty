#include "monty.h"

/**
 * parse_line - parses a line from a file
 * @line: line to parse
 * @stack: pointer to the stack
 */

void parse_line(char *line, stack_t **stack)
{
	instruction_t opcodes[] = {
		{"push", push_}, {"pall", pall_},
		{"pint", pint_}, {"pop", pop_},
		{"swap", swap_}, {"add", add_},
		{"nop", nop_}, {"sub", sub_},
		{"div", div_}, {"mul", mul_},
		{"mod", mod_}, {"pchar", pchar_},
		{"pstr", pstr_}, {"rotl", rotl_},
		{"rotr", rotr_}, {"stack", stack_queue},
		{"queue", stack_queue}, {NULL, NULL}
	};
	int i = 0;

	utls.args[0] = strtok(line, " \n\t");
	if (utls.args[0] && utls.args[0][0] == '#')
		return;
	utls.args[1] = strtok(NULL, " \n\t");
	if (utls.args[0])
	{
		while (opcodes[i].opcode)
		{
			if (strcmp(opcodes[i].opcode, utls.args[0]) == 0)
			{
				opcodes[i].f(stack, utls.line_n);
				return;
			}
			i++;
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", utls.line_n, utls.args[0]);
		fclose(utls.file_ptr);
		free(utls.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
