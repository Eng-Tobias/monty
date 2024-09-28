#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  /* For isdigit() */

typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void free_stack(stack_t *stack);

#endif /* MAIN_H */
