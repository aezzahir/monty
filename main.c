#include "monty.h"
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

int main(int argc, char **argv) {
    int fd;
    char *line;
    int i;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
	    i = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%d - %s", i, line);
		i++;
        free(line);
    }
    free(line);
    close(fd);
    }
    // Open the Monty byte code file
    // Read and execute the instructions
    // Clean up and exit
    return (EXIT_SUCCESS);
}
