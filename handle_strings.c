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
	if (stk == NULL || *stk == NULL)
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
/**
 * rotate_l - change pointer from the first node to the last node
 * @stk: stack
 * @len: number of lines in the stack
*/
void rotate_l(stack_t **stk, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	/* check if the stack is empty or conatins only one element */
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		return;
	}
	/* assign stack to temporary stack*/
	temp = *stk;
	/* loop through the stack to get last element */
	while (temp->next != NULL)
		/* assign the value of last element to temp */
		temp = temp->next;
	temp->next = *stk;
	(*stk)->prev = temp;
	*stk = (*stk)->next;
	(*stk)->prev->next = NULL;
	(*stk)->prev = NULL;
}

/**
 * rotate_r - change the last node of the stack to be at top
 * @stk: stack
 * @len: number of lines
 * Return: void
*/
void rotate_r(stack_t **stk, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	/* check if empty or contains only one value */
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;
	temp = *stk;
	/* loop to get last element in stack */
	while (temp->next != NULL)
		temp = temp->next;
	/* swap */
	temp->next = *stk;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stk)->prev = temp;
	(*stk) = temp;
}