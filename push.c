#include "monty.h"
#include <ctype.h>

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number where the opcode appears
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    stack_t *new_node;
    int n;

    if (arg == NULL || !isdigit(arg[0]))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
