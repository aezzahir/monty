#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#define BUFFER_SIZE 32
typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} monty_stack_t;


typedef struct instruction_s {
    char *opcode;
    void (*f)(monty_stack_t **stack, unsigned int line_number);
} instruction_t;



size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(char *str, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

void push(monty_stack_t **stack, unsigned int line_number);
void pall(monty_stack_t **stack, unsigned int line_number);
void parse_and_execute(char *line, monty_stack_t **stack);

#endif /* MONTY_H */
