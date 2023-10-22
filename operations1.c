#include "monty.h"

/**
 * nd_mul - multiply the top nodes in the stack
 * @stk: stack
 * @num: number of lines in stack
 * Return: void
*/
void nd_mul(stack_t **stk, unsigned int num)
{
	int mult;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "multiply");
	(*stk) = (*stk)->next;
	mult = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = mult;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

/**
 * nd_mod - get modulus of the two top elements in a stack
 * @stk: the stack
 * @num: number of lines in stack
 * Return: void
*/
void nd_mod(stack_t **stk, unsigned int num)
{
	int md;

	if (stk == NULL || (*stk) == NULL || (*stk)->next == NULL)
		err2(8, num, "modulus");
	if ((*stk)->n == 0)
		err2(9, num);
	(*stk) = (*stk)->next;
	md = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = md;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
