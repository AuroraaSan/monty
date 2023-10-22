#include "monty.h"

/**
 * nothing - function that does nothing
 * @stk: stack
 * @num: line number
 * Return: void
*/
void nothing(stack_t **stk, unsigned int num)
{
	/* do nothing no operation */
	(void)stk;
	(void)num;
}

/**
 * nd_swp - swap two nodes in the stack
 * @stk: stack
 * @num: line number for opcode
 * Return: void
*/
void nd_swp(stack_t **stk, unsigned int num)
{
	stack_t *temp;
	/* check if stack null to raise error */
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "swap");
	/* set value of temp stack to swap nodes */
	temp = (*stk)->next;
	(*stk)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stk;
	temp->next = *stk;
	(*stk)->prev = temp;
	temp->prev = NULL;
	*stk = temp;
}

