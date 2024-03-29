#include "monty.h"
#include <stdio.h>

/**
 * push_error - Print error message for push opcode
 * @line_number: Line number in the file
 *
 * Return: void
 */
void push_error(unsigned int line_number)
{
    fprintf(stderr, "L%d: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
}
