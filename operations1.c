#include "monty.h"



/**
 * nd_mod - get modulus of the two top elements in a stack
 * @stk: the stack
 * @num: number of lines in stack
 * Return: void
*/
void nd_mod(stack_t **stk, unsigned int num)
{
	int md;
	/* check if the stack is empty or not */
	if (stk == NULL || (*stk) == NULL || (*stk)->next == NULL)
		err2(8, num, "modulus");
	/* check if the calue of head not zero to raise error if so */
	if ((*stk)->n == 0)
		err2(9, num);
	/* operate the modulus for the top two values in the stack and add the result to md */
	(*stk) = (*stk)->next;
	md = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = md;
	/* free nodes */
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
/**
 * nd_mul - multiply the top nodes in the stack
 * @stk: stack
 * @num: number of lines in stack
 * Return: void
*/
void nd_mul(stack_t **stk, unsigned int num)
{
	int mult;
	/* check if the stack empty to raise error*/
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "multiply");
	/* multiplty the top two values of the stack and add the result to mult */
	(*stk) = (*stk)->next;
	mult = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = mult;
	/* free nodes */
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

