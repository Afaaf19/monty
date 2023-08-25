#include "monty.h"
/**
 * _mode - mode distinguish between stack and queue, 0 if queue, 1 if stack
 * @top: the top of the double list
 * @line_nb: line number of opcode
 * Return: void
 */
void _mode(stack_t **top, unsigned int line_nb)
{
	(void)top;
	(void)line_nb;

	if (strcmp(info_s.opcode, "queue") == 0)
		info_s.mode = 1;
	else if (strcmp(info_s.opcode, "stack") == 0)
		info_s.mode = 0;
}

