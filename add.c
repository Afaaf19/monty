#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @top: head of double list
 * @line_nb:  line number of opcode
 * Return: void
 */

void _add(stack_t **top, unsigned int line_nb)
{
	int val = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	val = (*top)->n;
	_pop(&info_s.top, info_s.line_nb);
	(*top)->n += val;
}
