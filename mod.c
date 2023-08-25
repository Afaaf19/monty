#include "monty.h"

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @top: head of double list
 * @line_nb: line number of opcode
 * Return: none
 */
void _mod(stack_t **top, unsigned int line_nb)
{
	int val = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
	val = (*top)->n;
	_pop(&info_s.top, info_s.line_nb);
	(*top)->n %= val;
}
