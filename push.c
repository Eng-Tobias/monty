#include "main.h"

/**
 * push - Pushes an integer onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Current line number in the bytecode file
 **/
void push(stack_t **stack, unsigned int line_number) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = line_number;
    new_node->next = *stack;
    *stack = new_node;
}
