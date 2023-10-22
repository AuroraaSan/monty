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

	va_start(agg, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(agg, char *));
			break;
		case 3:
			num = va_arg(agg, int);
			opcode = va_arg(agg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(agg, int));
			break;
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
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(agg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(agg, int));
			break;
		case 8:
			num = va_arg(agg, unsigned int);
			opcode = va_arg(agg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(agg, unsigned int));
			break;
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
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	free_nd();
	exit(EXIT_FAILURE);
}
