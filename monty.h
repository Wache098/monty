#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITERS " \t\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, int value);
void push_handler(stack_t **stack, unsigned int line_number, char *argument);
void pall_handler(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void handle_error(char **line, FILE **file, stack_t **stack);
void free_resources(char **line, FILE **file, stack_t **stack);
void pint_handler(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
