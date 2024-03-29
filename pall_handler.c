#include "monty.h"

/**
 * pall_handler - Handles the pall opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
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
