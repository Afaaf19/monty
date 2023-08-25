#include "monty.h"

/**
 * _push - function that adds a new node to the top
 * @top: head of the double list
 * @line_nb: line number of opcode
 * Return: void
 */

void _push(stack_t **top, unsigned int line_nb)
{
	int i = 0;
	stack_t *new, *last;

	(void)line_nb;
	if (top == 0)
		return;
	new = malloc(sizeof(stack_t));
	if (new == 0)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	new->n = info_s.push_val;
	if (info_s.mode == 0 || !*top)
	{
		if (*top)
		{
			new->next = *top;
			(*top)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*top = new;
	}
	else if (info_s.mode == 1)
	{
		last = *top;
		for (i = 0; last; i++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}
