#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Doubly linked list node
typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} monty_stack_t;

// Opcode and function association
typedef struct instruction_s {
    char *opcode;
    void (*f)(monty_stack_t **stack, unsigned int line_number);
} instruction_t;

// Function prototypes
void push(monty_stack_t **stack, unsigned int line_number);
void pall(monty_stack_t **stack, unsigned int line_number);
void parse_and_execute(char *line, monty_stack_t **stack);

#endif /* MONTY_H */
