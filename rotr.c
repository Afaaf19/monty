#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: void
 */

void _rotr(stack_t **top, unsigned int line_nb)
{
	stack_t *last = *top;
	int i;

	if (!*top || (*top)->next == NULL)
		return;
	(void)line_nb;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	last->prev->next = NULL;
	(*top)->prev = last;
	(*top) = last;
	last->prev = NULL;
}
