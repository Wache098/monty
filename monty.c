#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode, *argument;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        argument = strtok(NULL, " \t\n");

        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                handle_error(&line, &file, &stack);
            }
            pall_handler(&stack, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall_handler(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            handle_error(&line, &file, &stack);
        }
    }

    free_resources(&line, &file, &stack);

    return EXIT_SUCCESS;
}
