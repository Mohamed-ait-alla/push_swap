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

// function to create new node
t_stack	*new_node(int value);

// function to add a new node
void    push(t_stack **stack, int value);

// function to convert a string to an integer
long	ft_atoi(const char *str);

// function to check for duplicate in a stack
int	ft_check_duplicates(t_stack *stack, int value);

// function to check for non integer like : 2r 4t
int ft_check_for_non_integers(const char *s);

// function to clear one element in a stack
void	ft_del_one(t_stack **stack);

// function to check for an empty stack
int	check_for_empty_stack(t_stack *stack);

// function for actions: sa and sb
void	ft_swap(t_stack **stack);

// function for actions : swap a and b at the same time
void	ft_swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

// function for actions: pa and pb
void	ft_push(t_stack **stack_a, t_stack **stack_b);

// function for actions: ra and rb
void	ft_rotate(t_stack **stack);

// function for actions: ra and rb at the same time
void	ft_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

// function for actions: rra and rrb
void	ft_reverse_rotate(t_stack **stack);

// function for actions: rra and rrb at the same time
void	ft_reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

#endif