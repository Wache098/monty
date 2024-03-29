#include "monty.h"

/**
 * free_resources - Frees resources allocated during program execution
 * @line: Pointer to the current line buffer
 * @file: Pointer to the current file stream
 * @stack: Pointer to the stack
 */
void free_resources(char **line, FILE **file, stack_t **stack)
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
}
