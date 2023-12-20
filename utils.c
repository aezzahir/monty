#include "monty.h"

void parse_and_execute(char *line, monty_stack_t **stack) {
    unsigned int n;
    int i;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    n = (unsigned int)atoi(line + 5);
    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strncmp(line, instructions[i].opcode, 4) == 0)
        {
            instructions[i].f(stack, n);
            break;
        }
    }
}
