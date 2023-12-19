#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element
 * @next: points to the next element
 */
typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s {
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

// Function prototypes here
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
// utils functions 
void parse_and_execute(FILE *file, stack_t **stack);

#endif /* MONTY_H */
