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
	/* checks if there is input from user or not */
	if (argc != 2)
	{
		/* if no input print USAGE: monty file*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* if there is an input, use open file function to operate the program */
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
	/* create a stack for nodes to add */
	stack_t *nd;
	/* allocate memory for stack */
	nd = malloc(sizeof(stack_t));
	/* if no memory, raise error */
	if (nd == NULL)
		err1(4);
	/* else, add the node to stack */
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
	/* create temporary stack for free nodes */
	stack_t *temp;
	/* if pointer heade points to no nodes, do nothing*/
	if (head == NULL)
		return;
	/* iterate through the stack to free all nodes */
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
	/* create temporary stack */
	stack_t *temp;
	/* check if there a node and raise error if null */
	if (nw_nod == NULL || *nw_nod == NULL)
		exit(EXIT_FAILURE);
	/* if no head, create the node to be the head */
	if (head == NULL)
	{
		head = *nw_nod;
		return;
	}
	/* swap */
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *nw_nod;
	(*nw_nod)->prev = temp;

}
