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
    /* check is stack null or not to raise error */
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "add");
    /* set the sum of the top two nodes to the variable s */
	(*stk) = (*stk)->next;
	s = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = s;
    /* free node */
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
    /* check if the stack empty or not */
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "sub");
    /* subtract the top two values in the stack and add the result to variable sub */
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
    /* check is stack empty or not to raise error */
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		err2(8, num, "div");
    /* check if the dividor is zero to raise division error */
	if ((*stk)->n == 0)
		err2(9, num);
    /* divide the top two values in the stack and add the result to variable div */
	(*stk) = (*stk)->next;
	div = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = div;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
