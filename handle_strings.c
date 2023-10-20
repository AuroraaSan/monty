#include "header.h"


/**
 * string_print - print a string using its ascii code
 * @stk: stack with ascii code
 * @len: number of lines in function
 * Return: void
*/
void string_print(stack_t **stk, __attribute__((unused))unsigned int len)
{
	/* ascii number */
	int asc;
	/* temporary stack */
	stack_t *temp;
	
	/* check if stack empty */
	if (stk == null || *stk == NULL)
	{
		/* display empty line */
		printf("\n");
		return;
	}
	/* set temporary stack holding values in stack */
	temp = *stk;
	/* loop through to print each char */
	while (temp != NULL)
	{
		/* set ascii value of top velue in temp stack */
		asc = temp->n;
		/* while the value in the range of ascii format */
		if (asc <= 0 || asc > 127)
			break;
		/* print the string */
		printf("%c", asc);
		/* continue to the second char to print */
		temp = temp->next;
	}
	/* print new line */
	printf("\n");
}



/**
 * charcter_print - print the char of the provided ascii value
 * @stk: ptr to the node at the top of stack
 * @num_line: number of lines
 * Return: void
*/

void character_print(stack_t **stk, unsigned int num_line)
{
	int asc;

	/* check if no stack */
	if (stk == NULL || *stk == NULL)
		/* print error message if true */
		error_str(11, num_line);
	/* assign the value on top of stack to asc */
	asc = (*stk)->n;
	/* check if not available char in ascii system */
	if (asc < 0 || asc > 127)
		/* print error message */
		error_str(10, num_line);
	/*else, print the character of the provided ascii*/
	printf("%c\n", asc);
}
