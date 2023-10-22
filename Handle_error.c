 #include "monty.h"

/**
 * err1 - Prints appropiate error messages
 * @code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 */
void err1(int code, ...)
{
	va_list agg;
	char *opcode;
	int num;
/* to access variables in var function */
	va_start(agg, code);
	/* error cases for the program */
	switch (code)
	{
		/* raise this when no file entered to the program */
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		/* when can't open the file entered to the program */
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(agg, char *));
			break;
		/* when the instruction isn't listed in list of instruction in the program */
		case 3:
			num = va_arg(agg, int);
			opcode = va_arg(agg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, opcode);
			break;
		/* when failed to allocate memory for the variable */
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		/* when error while pushing to stack */
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(agg, int));
			break;
		/* default state, do nothing */
		default:
			break;
	}
	free_nd();
	exit(EXIT_FAILURE);
}

/**
 * err2 - handles errors.
 * @code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void err2(int code, ...)
{
	va_list agg;
	char *opcode;
	int num;

	va_start(agg, code);
	switch (code)
	{
		/* when stack has no nodes and can't print */
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(agg, int));
			break;
		/* empty stack can't pop nodes from */
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(agg, int));
			break;
		/* stack too short to make the operation eg.; add*/
		case 8:
			num = va_arg(agg, unsigned int);
			opcode = va_arg(agg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, opcode);
			break;
		/* dividing a number by zero using nd_by function */
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(agg, unsigned int));
			break;
		/* default state, do nothing */
		default:
			break;
	}
	free_nd();
	exit(EXIT_FAILURE);
}

/**
 * err_str - handles errors.
 * @code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void error_string(int code, ...)
{
	va_list agg;
	int num;

	va_start(agg, code);
	num = va_arg(agg, int);
	switch (code)
	{
		/* error in print character function when value out of range */
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		/* error in print character due to empty stack */
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		/* default state, do nothing*/
		default:
			break;
	}
	free_nd();
	exit(EXIT_FAILURE);
}

