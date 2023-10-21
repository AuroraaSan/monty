#include "header.h"

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
 * top_p - function to print the node at top
 * @stk: stack
 * @num: line number
 * Return: void
*/
void top_p(stack_t **stk, unsigned int num)
{
    stack_t *temp;

    if(stk == NULL || *stk == NULL)
        err2(7, num);
    
    temp = *stk;
    *stk = temp->next;
    if(*stk != NULL)
        (*stk)->prev = NULL;
    free(temp);
}
/**
 * nothing - function that does nothing
 * @stk: stack
 * @num: line number
 * Return: void
*/
void nothing(stack_t **stk, unsigned int num)
{
    (void)stk;
    (void)num;
}
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
