#include "monty.h"
/**
 * _swap - swap swaps the top two elements of the stack
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: void
 */
void _swap(stack_t **top, unsigned int line_nb)
{
	stack_t *tmp;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	tmp = *top;
	tmp->prev = tmp->next;
	if ((*top)->next->next == NULL)
		tmp->next = NULL;
	else
	{
		tmp->next = tmp->next->next;
		tmp->next->prev = *top;
	}
	*top = tmp->prev;
	(*top)->prev = NULL;
	(*top)->next = tmp;
}
