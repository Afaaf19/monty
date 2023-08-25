#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: void
 */

void _pint(stack_t **top, unsigned int line_nb)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*top)->n);
	fflush(stdout);

}
