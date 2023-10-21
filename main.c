#include "monty.h"
stack_t *head = NULL;

/**
 * main - main function of the program
 * @argc: argumenct counter
 * @argv: array of program arguments
 * Return: 0
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: header file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	n_free();
	return (0);
}

/**
 * nd_new - create a node
 * @num: node int
 * Return: ptr to the node is added or null if not
*/
stack_t *nd_new(int num)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		err1(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = num;
	return (nd);
}


 /**
  * n_free - free nodes in stack
  * Return: void
 */
void n_free(void)
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
 * q_add - function to add a node to a queue
 * @nd_new: the new node to be added
 * @len: line number to be added
 * Return: void
*/
void q_add(stack_t **nd_new, __attribute__((unused))unsigned int len)
{
	stack_t *temp;

	if (nd_new == NULL || *nd_new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nd_new;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *nd_new;
	(*nd_new)->prev = temp;
}

