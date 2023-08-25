#include "monty.h"
/**
 * _pop -  removes the top element of the stack
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: void
 */
void _pop(stack_t **top, unsigned int line_nb)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		*top = (*top)->next;
		free((*top)->prev);
		(*top)->prev = NULL;
	}
}
