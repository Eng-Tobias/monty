#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = malloc(sizeof(char) * 100);
    size_t len = 100;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char opcode[100];

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        free(line);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        free(line);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, len, file) != NULL)
    {
        line_number++;
        sscanf(line, "%s", opcode);
        if (opcode[0] == '\0' || opcode[0] == '#')
            continue;

        if (strcmp(opcode, "push") == 0)
            push(&stack, line_number);
        else if (strcmp(opcode, "pall") == 0)
            pall(&stack, line_number);
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            free_stack(stack);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (0);
}
