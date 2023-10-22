#include "monty.h"

/**
 * open_file - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void open_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		err1(2, f_name);

	f_read(fd);
	fclose(fd);
}


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
 * line_p - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @num: line number
 * @fr:  storage fr. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int line_p(char *buff, int num, int fr)
{
	char *opcode, *value;
	const char *delim = "\n ";
/* raise error when buffer empty*/
	if (buff == NULL)
		err1(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (fr);
	value = strtok(NULL, delim);
/* print  0 when stack or 1 when queue*/
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	f_function(opcode, value, num, fr);
	return (fr);
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


/**
 * f_call - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @value: string representing a numeric value.
 * @len: line numeber for the instruction.
 * @fr: fr specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void f_call(op_func func, char *op, char *value, int len, int fr)
{
	stack_t *nd;
	int fg;
	int x;

	fg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			fg = -1;
		}
		if (value == NULL)
			err1(5, len);
		for (x = 0; value[x] != '\0'; x++)
		{
			if (isdigit(value[x]) == 0)
				err1(5, len);
		}
		nd = nd_new(atoi(value) * fg);
		if (fr == 0)
			func(&nd, len);
		if (fr == 1)
			q_add(&nd, len);
	}
	else
		func(&head, len);
}
