#include "monty.h"

void push(monty_stack_t **stack, unsigned int line_number) {
    monty_stack_t *new_node = malloc(sizeof(monty_stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = line_number;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

void pall(monty_stack_t **stack, unsigned int line_number) {
    (void)line_number; // Unused parameter
    monty_stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
