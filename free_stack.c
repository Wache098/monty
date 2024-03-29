#include "monty.h"

/**
 * free_stack - Frees a stack
 * @stack: Double pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}
