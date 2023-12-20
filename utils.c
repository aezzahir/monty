#include "monty.h"

int is_number(char *str) {
    if (!str)
        return 0;
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


void parse_and_execute(char *line, monty_stack_t **stack) {
    char *opcode;
    char *num_str;
    static unsigned int line_number = 0;
    int i, n;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    line_number++;
    if (line == NULL) {
        fprintf(stderr, "Error: Null line passed to parse_and_execute\n");
        exit(EXIT_FAILURE);
    }

    opcode = strtok(line, " \t\n");
    if (opcode == NULL) {
        return;
    }

    num_str = strtok(NULL, " \t\n");
    if (!is_number(num_str)) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    n = (unsigned int)atoi(num_str);

    for (i = 0; instructions[i].opcode != NULL; i++) {
        if (strcmp(opcode, instructions[i].opcode) == 0) {
            instructions[i].f(stack, n);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
