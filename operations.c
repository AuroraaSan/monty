#include "monty.h"

/**
 * stk_print - Adds a node to the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @num: line number of  the opcode.
 */
void stk_print(stack_t **stk, unsigned int num)
{
	stack_t *temp;
	/* check if stack null */
	(void) num;
	if (stk == NULL)
		exit(EXIT_FAILURE);
	/* assign temporary stack */
	temp = *stk;
	/* loop thtough the stack to print each node */
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		/* increment */
		temp = temp->next;
	}
}
/**
 * stack_add - Adds a node to the stack.
 * @nw_nod: Pointer to the new node.
 * @len: Interger representing the line number of of the opcode.
 */
void stack_add(stack_t **nw_nod, __attribute__((unused))unsigned int len)
{
	stack_t *temp;
	/* check if node is Null (no node) to raise error*/
	if (nw_nod == NULL || *nw_nod == NULL)
		exit(EXIT_FAILURE);
	/* check if no head to add one */
	if (head == NULL)
	{
		head = *nw_nod;
		return;
	}
	/* shift values */
	temp = head;
	head = *nw_nod;
	head->next = temp;
	temp->prev = head;
}
/**
 * pop_p - Adds a node to the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @num: Interger representing the line number of of the opcode.
 */
void pop_p(stack_t **stk, unsigned int num)
{
	/* set temporary stack */
	stack_t *temp;
	/* check if stk empty to raise error */
	if (stk == NULL || *stk == NULL)
		err2(7, num);
	/* set the temporary stack */
	temp = *stk;
	/* skip the first node to be deleted*/
	*stk = temp->next;
	/* check if the next node isn't null */
	if (*stk != NULL)
		/* set the previous to null to make this the head of stack */
		(*stk)->prev = NULL;
	/* free the temp stack */
	free(temp);
}

/**
 * top_p - Prints the top node of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @num: Interger representing the line number of of the opcode.
 */
void top_p(stack_t **stk, unsigned int num)
{
	/* check if stack empty to raise error */
	if (stk == NULL || *stk == NULL)
		err2(6, num);
	/* print the value of the top of stack */
	printf("%d\n", (*stk)->n);
}
