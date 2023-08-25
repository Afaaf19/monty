#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack
 * @top: head of the double list
 * @line_nb: line number of opcode
 * Return: void
 */
void _pchar(stack_t **top, unsigned int line_nb)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 127 || (*top)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}
