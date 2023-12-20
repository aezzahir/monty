#include "monty.h"

int is_number(char *str) {
    if (*str == '-' || *str == '+') {
        str++;
    }
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

#include "monty.h"

void parse_and_execute(char *line, monty_stack_t **stack) {
    char *opcode;
    char *num_str;
    unsigned int n = 0;
    int i;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    if (line == NULL) {
        fprintf(stderr, "Error: Null line passed to parse_and_execute\n");
        exit(EXIT_FAILURE);
    }

    opcode = strtok(line, " \t\n");
    if (opcode == NULL) {
        return;
    }

    num_str = strtok(NULL, " \t\n");
    if (num_str != NULL) {
        if (!is_number(num_str)) {
            fprintf(stderr, "L%d: usage: push integer\n", n);
            exit(EXIT_FAILURE);
        }
        n = (unsigned int)atoi(num_str);
    }

    for (i = 0; instructions[i].opcode != NULL; i++) {
        if (strcmp(opcode, instructions[i].opcode) == 0) {
            if (n != 0)
                instructions[i].f(stack, n);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
    exit(EXIT_FAILURE);
}
