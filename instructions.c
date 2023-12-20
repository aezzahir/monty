#include "monty.h"

void push(monty_stack_t **stack, unsigned int value) {
    monty_stack_t *new_node;
    
    new_node = (monty_stack_t *)malloc(sizeof(monty_stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}


void pall(monty_stack_t **stack, unsigned int line_number) {
    monty_stack_t *current;
    
    (void)line_number;
    current = *stack;
    printf("")
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
