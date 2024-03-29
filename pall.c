#include "monty.h"
#include <stdio.h>

/**
 * pall_handler - Prints all values on the stack
 * @stack: Pointer to the top of the stack
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
