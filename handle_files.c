#include "monty.h"

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
 * open_file - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void open_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");
	/* check if there is no file to raise error */
	if (f_name == NULL || fd == NULL)
		err1(2, f_name);
	/* read the file and close it */
	f_read(fd);
	fclose(fd);
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
	/* if the operator is push */
	if (strcmp(op, "push") == 0)
	{
		/* Check if 'value' is not NULL and starts with a '-' sign */
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			fg = -1; /* Set 'fg' to -1 to indicate a negative value */
		}
		if (value == NULL) /* Check if 'value' is NULL */
			err1(5, len);
		for (x = 0; value[x] != '\0'; x++) /* Loop through characters in 'value' until the null terminator */
		{
			if (isdigit(value[x]) == 0)
				err1(5, len);
		}
		/* Create a new node with the integer value from 'value' and 'fg' as a multiplie */
		nd = nd_new(atoi(value) * fg);
		if (fr == 0)
			func(&nd, len);
		if (fr == 1)
			q_add(&nd, len);
	}
	else
	/* If 'op' is not "push", call 'func' with 'head' and 'len' */
		func(&head, len);
}
