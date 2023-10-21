#include "header.h"

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
