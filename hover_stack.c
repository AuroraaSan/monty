#include "header.h"
/* these functions handle the pointer pointing to the head or bottom 
of stack and vise versa */

/**
 * rotate_l - change pointer from the first node to the last node
 * @stk: stack
 * @len: number of lines in the stack
*/
void rotate_l(stack_t **stack, __attribute__((unused))unsigned int len)
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
void rotate_r(stack_t **stack, __attribute__((unused))unsigned int len)
{
	stack_t = temp;

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
