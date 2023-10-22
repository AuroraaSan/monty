#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nd();
	return (0);
}

/**
 * nd_new - Creates a node.
 * @nx: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *nd_new(int nx)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		err1(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = nx;
	return (nd);
}

/**
 * free_nd- Frees nodes in the stack.
 */
void free_nd(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * q_add - Adds a node to the queue.
 * @nw_nod: Pointer to the new node.
 * @len: line number of the opcode.
 */
void q_add(stack_t **nw_nod, __attribute__((unused))unsigned int len)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *nw_nod;
	(*nw_nod)->prev = temp;

}
