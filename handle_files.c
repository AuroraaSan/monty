#include "monty.h"

/**
 * f_open - open file
 * @f_name: name of the file
 * Return: void
*/
void f_open(char *f_name)
{
    FILE *fd = fopen(f_name, "r");

    if (f_name == NULL || fd == NULL)
        err1(2, f_name);

    f_read(fd);
    fclose(fd);
}

/**
 * f_read: read file
 * @fd: file desc pointer
 * Return: void
*/
void f_read(FILE *fd)
{
    int num, fr = 0;
    char *buf = NULL;
    size_t ln = 0;

    for(num = 1; getline(&buf, &ln, fd) != -1; num++)
        fr = line_p(buf, num, fr);
    free(buf);
}
/**
 * line_p - separate lines
 * @buf: buffer
 * @num: number of lines
 * @fr: format for storage
 * Return: 0 if stack and 1 if queue
*/
int line_p(char *buf, int num, int fr)
{
    char *operation_c, *val;
    const char *dlm = "\n";

    if (buf == NULL)
        err1(4);
    
    operation_c = strtok(buf, dlm);
    if (operation_c == NULL)
        return (fr);
    val = strtok(NULL, dlm);

    if (strcmp(operation_c, "stack") == 0)
        return (0);
    if (strcmp(operation_c, "queue") == 0)
        return (1);
    f_function(operation_c, val, num, fr);
    return(fr);
}

/**
 * f_function - gets the function needed for the operation
 * @operation_c: opcode
 * @val: arg value
 * @fr: format for storage
 * @num:number line
 * Return: void
*/
void f_function(char *operation_c, char *val, int num, int fr)
{
    int x;
    int fg;

    instruction_t list_f[] = {
        {"push", stack_add},
        {"pint", top_p},
        {"pall", stk_print},
        {"pop", pop_p},
        {"add", nd_plus},
        {"nop", nothing},
        {"swap", nd_swp},
        {"sub", nd_minus},
        {"mul", nd_mul},
        {"pchar", character_print},
        {"rotr", rotate_r},
        {"pstr", string_print},
        {"rotl", rotate_l},
        {"div", nd_by},
        {"mod", nd_mod},
        {NULL, NULL}
    };

    if(operation_c[0] == '#')
        return;
    for (fg = 1, x = 0; list_f[x].operation_c != NULL; x++)
    {
        if (strcmp(operation_c, list_f[x].operation_c) == 0)
        {
            f_call(list_f[x].f, operation_c, val, num, fr);
            fg = 0;
        }

    }
    if (fg == 1)
        err1(3, num, operation_c);
}
/**
 * f_call - call the function to be operated
 * @fun: a ptr to the function
 * @op_c: operation code
 * @val: value in str
 * @num: number line
 * @fr: format for storage
 * Return: void
*/

void f_call(op_func fun, char *op_c, char *val, int num, int fr)
{
    stack_t *nd;
    int fg;
    int x;

    fg = 1;
    if (strcmp(op_c, "push") == 0)
    {
        if(val != NULL && val[0] == '-')
        {
            val += 1;
            fg = -1;
        }
        if (val == NULL)
            err1(5, num);
        for (x = 0; val[x] != '\0'; x++)
        {
            if(isdigit(val[x]) == 0)
                err1(5, num);
        }
        nd = nd_new(atoi(val) * fg);
        if (fr == 0)
            fun(&nd, num);
        if (fr == 1)
            q_add(&nd, num);
    }
    else
        fun(&head, num);
}