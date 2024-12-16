#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

    char    **ft_split(char const *s, char c);
#endif