#include "monty.h"



void err1(int code, ...)
{
	va_list agg;
	char *pp;
	int num;

	va_start(agg, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(agg, char *));
			break;
		case 3:
			num = va_arg(agg, int);
			pp = va_arg(agg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, pp);
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
	n_free();
	exit(EXIT_FAILURE);
}

void err2(int code, ...)
{
	va_list agg;
	char *pp;
	int num;

	va_start(agg, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(agg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(agg, int));
			break;
		case 8:
			num = va_arg(agg, unsigned int);
			pp = va_arg(agg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, pp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(agg, unsigned int));
			break;
		default:
			break;
	}
	n_free();
	exit(EXIT_FAILURE);
}

void error_str(int code, ...)
{
	va_list argg;
	int num;

	va_start(argg, code);
	num = va_arg(argg, int);
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
	n_free();
	exit(EXIT_FAILURE);
}

#include "monty.h"
/**
 * err1 - print error message according to each case
 * @code: error code
 * (1) => user does not give file or more than one file.
 * (2) => file is not a file that can be opened or read.
 * (3) => file contains an invalid instruction.
 * (4) =>  program is unable to malloc more memory.
 * (5) => parameter passed to the instruction "push" is not an int.
*/
void err1(int code, ...)
{
	va_list agg;
	char *pp;
	int num;

	va_start(agg, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(agg, char *));
			break;
		case 3:
			num = va_arg(agg, int);
			pp = va_arg(agg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, pp);
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
	va_end(agg);
	n_free();
	exit(EXIT_FAILURE);
}
/**
 * err2 - handles error by printing appropriate messages
 * @code: error code to print the message
 * (6) => stack it empty for pint.
 * (7) => stack it empty for pop.
 * (8) => stack is too short for operation.
 * (9) => Division by 0.
 * Return: void
*/
void err2(int code, ...)
{
	va_list agg;

	va_start(agg, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(agg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(agg, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't %s, stack too short\n", va_arg(agg, unsigned int), va_arg(agg, char *));
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(agg, unsigned int));
			break;
		default:
			break;
	}
	va_end(agg);
	n_free();
	exit(EXIT_FAILURE);
}
/**
 * error_str - variadic func to handle error messages in strings
 * @code: number of error
 * Return: void
*/
void error_str(int code, ...)
{
	va_list argg;
	int num;

	va_start(argg, code);
	num = va_arg(argg, int);
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
	va_end(argg);
	n_free();
	exit(EXIT_FAILURE);
}
