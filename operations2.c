#include "monty.h"

/**
 * stack_add - function to add node to stack
 * @nd: node to be added
 * @num: line number
 * Return: void
*/
void stack_add(stack_t **nd, __attribute__((unused))unsigned int num)
{
	stack_t *temp;

	if (nd == NULL || *nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nd;
		return;
	}
	temp = head;
	head = *nd;
	head->next = temp;
	temp->prev = head;
}

/**
 * stk_print - print the stack nodes
 * @stk: pointer to the stack to be printed
 * @num: line number of operation code
 * Return: void
*/
void stk_print(stack_t **stk, unsigned int num)
{
	stack_t *temp;

	(void) num;
	if (stk == NULL)
		exit(EXIT_FAILURE);
	temp = *stk;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_p - pop the top node of the stack
 * @stk: stack
 * @num: line number of the opcode
 * Return: void
*/
void pop_p(stack_t **stk, unsigned int num)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL)
		err2(7, num);
	temp = *stk;
	*stk = temp->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	free(temp);
}
/**
 * top_p - print the top node in the stack
 * @stk: stack
 * @num: line number of opcode
 * Return: void
*/
void top_p(stack_t **stk, unsigned int num)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL)
		err2(7, num);
	temp = *stk;
	*stk = temp->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	free(temp);
}


/**
 * print_tp - print the top node of the stack
 * @stk: ptr to the top of the stack
 * @num: line number
 * Return: void
*/
void print_tp(stack_t **stk, unsigned int num)
{
	if (stk == NULL || *stk == NULL)
		err2(6, num);
	printf("%d\n", (*stk)->n);
}



