#include "header.h"

/**
 * error_str - variadic func to handle error messages in strings
 * @code: number of error
 * Return: void
*/
void error_str(int code, ...)
{
	va_list argg;
	int num;

	start_v(argg, code);
	num = arg_value(argg, int);
	switch (code)
	{
		case 10:
			fprintf(stderr, )
	}

}
