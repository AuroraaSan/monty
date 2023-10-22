#include "monty.h"

/**
 * nd_plus - add node to the top os stack
 * @stk: stack
 * @num: number line of opcode
 * Return: void
*/
void nd_plus(stack_t **stk, unsigned int num)
{
	int s;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "add");
	(*stk) = (*stk)->next;
	s = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = s;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * nd_minus - subtracts 2 nodes from top os stack
 * @stk: stack
 * @num: line number of opcode
 * Return: void
*/
void nd_minus(stack_t **stk, unsigned int num)
{
	int sub;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "sub");
	(*stk) = (*stk)->next;
	sub = (*stk)->n - (*stk)->prev->n;
	(*stk)->n = sub;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * nd_by - divide the top nodes of stack
 * @stk: stack
 * @num: line number of the opcode
 * Return: void
*/
void nd_by(stack_t **stk, unsigned int num)
{
	int div;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "div");
	if ((*stk)->n == 0)
		err2(9, num);
	(*stk) = (*stk)->next;
	div = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = div;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

