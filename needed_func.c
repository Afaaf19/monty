#include "monty.h"
/**
 * openfile - open a file
 * @filename: file name
 * Return: FILE
 */
FILE *openfile(char *filename)
{
	FILE *mfile;

	mfile = fopen(filename, "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (mfile);
}

/**
 * num_len - counts the number of characters in a number
 * @num: number
 * Return: length
 */
size_t num_len(int num)
{
	int length = 0;

	if (!num)
		return (1);
	if (num <= 0)
		length++;
	while (num != 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

/**
 * verify_number - verify if number for push opcode is valid or not
 * @token: token
 * Return: void
 */
void verify_number(char *token)
{
	int i = 0;

	if (atoi(token) < 0)
		i++;
	if ((isdigit(token[i]) && strlen(token) == num_len(atoi(token))) ||
		(token[0] == '-' && isdigit(token[1])))
		info_s.push_val = atoi(token);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", info_s.line_nb);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - frees stack
 * @top: head of the double list
 * Return: void
 */
void free_stack(stack_t *top)
{
	stack_t *nav, *nav2;

	nav = top;
	while (nav)
	{
		nav2 = nav->next;
		free(nav);
		nav = nav2;
	}
	info_s.top = NULL;
	fclose(info_s.mfile);
}
