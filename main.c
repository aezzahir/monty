#include "monty.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int fd;
    char *line;
    monty_stack_t *stack = NULL;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        line = get_next_line(fd);
        while (line != NULL)
        {
            parse_and_execute(line, &stack);
            free(line);
            line = get_next_line(fd);
        }
        close(fd);
    }
    return (0);
}
