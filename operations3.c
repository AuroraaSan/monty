#include "header.h"

/**
 * nd_swp - swap two nodes in the stack
 * @stk: stack
 * @num: line number for opcode
 * Return: void
*/
void nd_swp(stack_t **stk, unsigned int num)
{
    stack_t *temp;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        err2(8, num, "swap");
    temp = (*stk)->next;
    (*stk)->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = *stk;
    temp->next = *stk;
    (*stk)->prev = temp;
    temp->prev = NULL;
    *stk = temp;
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

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        err2(8, num, "sub");
    
    (*stk) = (*stk)->next;
    sub = (*stk)->n - (*stk)->prev->n;
    (*stk)->n = sub;
    free((*stk)->prev);
    (*stk)->prev = NULL;
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

    if(stk == NULL || *stk == NULL)
        err2(7, num);
    temp = *stk;
    *stk = temp->next;
    if (*stk != NULL)
        (*stk)->prev = NULL;
    free(temp);
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