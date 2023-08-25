#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack
 * @top: head of double list
 * @line_nib: line number of opcode
 * Return: void
 */
void _pstr(stack_t **top, unsigned int line_nb)
{
	stack_t *curr = *top;
	int i;
	(void)line_nb;

	for (i = 0; curr && curr->n != 0 &&
			!(curr->n > 127 || curr->n < 0); i++)
	{
		fprintf(stdout, "%c", curr->n);
		curr = curr->next;
	}
	fprintf(stdout, "\n");
}
