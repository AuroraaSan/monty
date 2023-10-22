#include "monty.h"
/**
 * f_read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */
void f_read(FILE *fd)
{
	int num, fr = 0;
	char *buff = NULL;
	size_t ln = 0;

	for (num = 1; getline(&buff, &ln, fd) != -1; num++)
	{
		fr = line_p(buff, num, fr);
	}
	free(buff);
}

/**
 * f_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @fr:  storage fr. If 0 Nodes will be entered as a stack.
 * @num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void f_function(char *opcode, char *value, int ln, int fr)
{
	int x;
	int flag;
/* list of all function used in program*/
	instruction_t f_list[] = {
		{"push", stack_add},
		{"pall", stk_print},
		{"pint", top_p},
		{"pop", pop_p},
		{"nop", nothing},
		{"swap", nd_swp},
		{"add", nd_plus},
		{"sub", nd_minus},
		{"div", nd_by},
		{"mul", nd_mul},
		{"mod", nd_mod},
		{"pchar", character_print},
		{"pstr", string_print},
		{"rotl", rotate_l},
		{"rotr", rotate_r},
		{NULL, NULL}
	};
/* if comment igonre it*/
	if (opcode[0] == '#')
		return;
/* iterate to see which function to call */
	for (flag = 1, x = 0; f_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, f_list[x].opcode) == 0)
		{
			f_call(f_list[x].f, opcode, value, ln, fr);
			flag = 0;
		}
	}
	if (flag == 1)
		err1(3, ln, opcode);
}
