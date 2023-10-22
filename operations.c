#include "monty.h"


/**
 * stack_add - Adds a node to the stack.
 * @nw_nod: Pointer to the new node.
 * @len: Interger representing the line number of of the opcode.
 */
void stack_add(stack_t **nw_nod, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (nw_nod == NULL || *nw_nod == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nw_nod;
		return;
	}
	temp = head;
	head = *nw_nod;
	head->next = temp;
	temp->prev = head;
}


/**
 * stk_print - Adds a node to the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @num: line number of  the opcode.
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
 * pop_p - Adds a node to the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @num: Interger representing the line number of of the opcode.
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
 * top_p - Prints the top node of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @num: Interger representing the line number of of the opcode.
 */
void top_p(stack_t **stk, unsigned int num)
{
	if (stk == NULL || *stk == NULL)
		err2(6, num);
	printf("%d\n", (*stk)->n);
}
