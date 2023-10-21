#include "monty.h"

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
			fprintf(stderr, "L%d: value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: stack empty\n", num);
			break;
		default:
			break;
	}
	n_free();
	exit(EXIT_FAILURE);
}
/**
 * err1 - print error message according to each case
 * @code: error code
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
			fprintf(stderr, "USAGE: header file\n");
			break;
		case 2:
			fprintf(stderr, "Error, can't open file %s\n", va_arg(agg, char *));
			break;
		case 3:
			num = va_arg(agg, int);
			pp = va_arg(agg, char *);
			fprintf(stderr, "L%d: unkown instruction %s\n", num, pp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push int\n", va_arg(agg, int));
			break;
		default:
			break;
	}
	n_free();
	exit(EXIT_FAILURE);
}
/**
 * err2 - handles error by printing appropriate messages
 * @code: error code to print the message
 * Return: void
*/
void err2(int code, ...)
{
	va_list agg;
	char *pp;
	int num;

	va_start(agg, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: stack empty can't pint\n", va_arg(agg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: empty stack can't pop", va_arg(agg, int));
			break;
		case 8:
			num = va_arg(agg, unsigned int);
			pp = va_arg(agg, char *);
			fprintf(stderr, "L%d: stack too short, can't %s\n", num, pp);
			break;
		case 9:
			fprintf(stderr, "L%d: error divided by zero", va_arg(agg, unsigned int));
			break;
		default:
			break;
	}
	n_free();
	exit(EXIT_FAILURE);
}
