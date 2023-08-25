#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: void
 */
void _mul(stack_t **top, unsigned int line_nb)
{
	int val = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	val = (*top)->n;
	_pop(&info_s.top, info_s.line_nb);
	(*top)->n *= val;
}
