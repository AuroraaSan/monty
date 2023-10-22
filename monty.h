#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
/* important headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

/* structs provided in the project */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @operation_c: the opcode
 * @f: function to handle the opcode
 *
 * Description: operation_c and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* external declarations */
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
/* prototypes for functions used in the project */
/* error files */
void error_string(int code, ...);
void err1(int code, ...);
void err2(int code, ...);
/* handle strings */
void character_print(stack_t **, unsigned int);
void string_print(stack_t **, unsigned int);
void rotate_l(stack_t **, unsigned int);
void rotate_r(stack_t **, unsigned int);
/* operations */
void nd_mod(stack_t **, unsigned int );
void nd_mul(stack_t **, unsigned int );
/* handle files */
void f_call(op_func , char *, char *, int , int );
void f_function(char *, char *, int , int );
void open_file(char *f_name);
void f_read(FILE *);
int line_p(char *buf, int num, int fr);
/* operations */
void stack_add(stack_t **, unsigned int);
void top_p(stack_t **, unsigned int);
void nd_plus(stack_t **, unsigned int);
void nothing(stack_t **, unsigned int);
void nd_swp(stack_t **, unsigned int);
void nd_minus(stack_t **, unsigned int);
int len_chars(FILE *);
void stk_print(stack_t **, unsigned int);
void nd_by(stack_t **, unsigned int);
void pop_p(stack_t **, unsigned int);
void q_add(stack_t **, unsigned int);
stack_t *nd_new(int num);
void free_nd(void);

#endif

