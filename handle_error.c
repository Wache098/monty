#include "monty.h"

/**
 * handle_error - Handles error conditions by freeing resources and exiting
 * @line: Pointer to the current line buffer
 * @file: Pointer to the current file stream
 * @stack: Pointer to the stack
 */
void handle_error(char **line, FILE **file, stack_t **stack)
{
    if (line != NULL && *line != NULL)
    {
        free(*line);
        *line = NULL;
    }
    
    if (file != NULL && *file != NULL)
    {
        fclose(*file);
        *file = NULL;
    }

    if (stack != NULL && *stack != NULL)
    {
        free_stack(stack);
    }

    exit(EXIT_FAILURE);
}
