#include "monty.h"

/**
 * character_print - Prints the Ascii value.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @num: Interger representing the line number of of the opcode.
 */
void character_print(stack_t **stk, unsigned int num)
{
	int asc;

	/* check if no stack */
	if (stk == NULL || *stk == NULL)
		/* print error message if true */
		error_string(11, num);
	/* assign the value on top of stack to asc */
	asc = (*stk)->n;
	/* check if not available char in ascii system */
	if (asc < 0 || asc > 127)
		/* print error message */
		error_string(10, num);
	/*else, print the character of the provided ascii*/
	printf("%c\n", asc);
}

/**
 * string_print - Prints a string.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
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
 * rotate_l - Rotates the first node of the stack to the bottom.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
 */
void rotate_l(stack_t **stk, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	/* check if the stack is empty or conatins only one element */
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;
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
 * rotate_r - Rotates the last node of the stack to the top.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @len: Interger representing the line number of of the opcode.
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
