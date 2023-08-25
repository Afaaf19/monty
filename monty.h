#ifndef MAIN_H
#define MAIN_H

/*libraries*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info - pcode info
 * @push_val: value to be pushed
 * @line_nb: line number of opcode
 * @opcode: opcode
 * @mfile: open file
 * @top: stack's top
 * @mode: 0 if stack, 1 if queue
 */
typedef struct info
{
	int push_val;
	unsigned int line_nb;
	char *opcode;
	FILE *mfile;
	stack_t *top;
	int mode;
} info;

info info_s;

/* prototypes */

void _push(stack_t **top, unsigned int line_number);
void _pall(stack_t **top, unsigned int line_number);
void _pint(stack_t **top, unsigned int line_number);
void _pop(stack_t **top, unsigned int line_number);
void _swap(stack_t **top, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line_number);
void _sub(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _mul(stack_t **top, unsigned int line_number);
void _mod(stack_t **top, unsigned int line_number);
void _pchar(stack_t **top, unsigned int line_number);
void _pstr(stack_t **top, unsigned int line_number);
void _rotl(stack_t **top, unsigned int line_number);
void _rotr(stack_t **top, unsigned int line_number);
void _mode(stack_t **top, unsigned int line_number);
FILE *openfile(char *filename);
size_t num_len(int num);
void verify_number(char *token);
void free_stack(stack_t *top);
void exec(void);
int main(int argc, char **argv);
#endif
