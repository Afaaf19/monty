#include "monty.h"

/**
 * _pall - function that prints all elements of a dlistint_t list
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: void
 */
void _pall(stack_t **top, unsigned int line_nb)
{
	stack_t *curr = *top;
	int i;

	(void)line_nb;
	for (i = 0; curr; i++)
	{
		fprintf(stdout, "%d\n", curr->n);
		curr = curr->next;
	}
	fflush(stdout);
}
