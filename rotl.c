#include "monty.h"

/**
 * _rot1 - rotates the stack to the top
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: void
 */
void _rotl(stack_t **top, unsigned int line_nb)
{
	stack_t *last = *top;
	int i;

	if (!*top)
		return;
	(void)line_nb;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	(*top)->prev = last;
	(*top) = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
}
