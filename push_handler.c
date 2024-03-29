#include "monty.h"
#include <ctype.h>
/**
 * push_handler - Handles the 'push' opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty bytecode file
 * @argument: Argument associated with the opcode
 */
void push_handler(stack_t **stack, unsigned int line_number, char *argument)
{
	 int value;

    if (!argument || !isdigit(*argument))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(argument);
    push(stack, value);
}
