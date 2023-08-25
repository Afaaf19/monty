#include "monty.h"

/**
 * exec - exec opcode
 * Return: none
 */
void exec(void)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _mode},
		{"stack", _mode},
		{NULL, NULL},
	};
	int j = 0;

	for (j = 0; ins[j].opcode; j++)
	{
		if (strcmp(info_s.opcode, ins[j].opcode) == 0)
		{
			ins[j].f(&info_s.top, info_s.line_nb);
			break;
		}
	}
	if (!ins[j].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				info_s.line_nb, info_s.opcode);
		free_stack(info_s.top);
		exit(EXIT_FAILURE);
	}
}
/**
 * remove_spaces - remove spaces
 * @str: string
 * Return: new string
 */
char *remove_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			break;
	}
	return (str);
}

/**
 * main -  count how many charachter in number
 * @argc: number
 * @argv: number
 * Return: the number lentgh
 */
int main(int argc, char **argv)
{
	char line[100], *token;
	int i = 0;

	info_s.mode = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info_s.mfile = openfile(argv[1]);
	while (fgets(line, sizeof(line), info_s.mfile) != NULL)
	{
		if (strlen(remove_spaces(line)) < 3 || remove_spaces(line)[0] == '#')
		{
			info_s.line_nb++;
			continue;
		}
		info_s.line_nb++;
		token = strtok(line, " \n");
		for (i = 0; token != NULL && i < 2; i++)
		{
			if (i == 0) /*first part command first loop*/
				info_s.opcode = token;
			if (strcmp(info_s.opcode, "push") != 0) /*if opcode is not push break*/
				break;
			if (i == 1)
				verify_number(token);
			token = strtok(NULL, " \n");
		}
		if (strcmp(info_s.opcode, "push") == 0 && i == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", info_s.line_nb);
			free_stack(info_s.top);
			exit(EXIT_FAILURE);
		}
		exec();
	}
	free_stack(info_s.top);
	exit(EXIT_SUCCESS);
}
