#include "monty.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int fd;
    char *line;
    monty_stack_t *stack = ;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    line = get_next_line(fd);
    while (line != NULL) {
        parse_and_execute(line, &stack);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);

    return (0);
}
