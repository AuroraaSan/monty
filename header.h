#ifndef HEADER_H
#define HEADER_H

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
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *operation_c;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* external declarations */
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
/* prototypes for functions used in the project */
void error_str(int code, ...);
void err1(int code, ...);
void err2(int code, ...);
void character_print(stack_t **stk, unsigned int num_line);
void string_print(stack_t **stk, __attribute__((unused))unsigned int len);
void rotate_l(stack_t **stk, __attribute__((unused))unsigned int len);
void rotate_r(stack_t **stk, __attribute__((unused))unsigned int len);
void nd_mod(stack_t **stk, unsigned int num);
void nd_mul(stack_t **stk, unsigned int num);
void f_call(op_func fun, char *op_c, char *val, int num, int fr);
void f_function(char *operation_c, char *val, int num, int fr);
void f_open(char *f_name);
void f_read(FILE *fd);
int line_p(char *buf, int num, int fr);
void stack_add(stack_t **nd, __attribute__((unused))unsigned int num);
void top_p(stack_t **stk, unsigned int num);
void nd_plus(stack_t **stk, unsigned int num);
void nothing(stack_t **stk, unsigned int num);
void nd_swp(stack_t **stk, unsigned int num);
void nd_minus(stack_t **stk, unsigned int num);
void top_p(stack_t **stk, unsigned int num);
void stk_print(stack_t **stk, unsigned int num);
void nd_by(stack_t **stk, unsigned int num);
void pop_p(stack_t **stk, unsigned int num);




#endif