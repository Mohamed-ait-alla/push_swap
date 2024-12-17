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


	void    push(t_stack **stack, int value);
    int check_for_empty_stack(t_stack *stack);
    void    ft_swap_a(t_stack **stack_a);
	void	ft_rotate_a(t_stack **stack_a);
#endif