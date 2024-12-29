#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h> // we don't need it when we gonna push that shit
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct s_stack {
    int				value;
	int				index;
	int				push_cost;
	bool	 		above_median;
	bool			cheapest;
	struct s_stack	*target_node;
    struct s_stack	*next;
} t_stack;


// we don't need this function when we gonna push this shit //
void	ft_display(t_stack *stack);



// function to create new node
t_stack	*new_node(int value);

// function to add a new node
void    push(t_stack **stack, int value);

// function to convert a string to an integer
long	ft_atol(const char *str);

// split function 
char	**ft_split(char const *s, char c);

// function to free the stack if an error occurs
void	ft_free_stack(t_stack **stack);

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

// function to initialize the stack a
void	ft_init_stack_a(t_stack **stack_a, char **argv);

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

// function to check if a stack is sorted or not
bool	ft_is_sorted(t_stack *stack);

// function to calculate the members of a stack
int	ft_stack_len(t_stack *stack);

// function to find the biggest node in the stack
t_stack	*ft_find_biggest_node(t_stack *stack);

// function to find the smallest node in the stack
t_stack	*ft_find_smallest_node(t_stack *stack);

// function to sort just three nodes in a stack
void	ft_sort_three(t_stack **stack_a);

// function to sort stack that has more thatn three nodes
void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b);

// function to init the nodes in a : set target, get the cheapest...
void	ft_init_nodes_of_a(t_stack *stack_a, t_stack *stack_b);

// function to get the index and set the above-medin to each node
void	ft_current_index(t_stack *stack);



// function to set the cheapest node in each stack
void	ft_set_cheapest(t_stack *stack);


// function to find the cheapest node
t_stack	*ft_get_cheapest_node(t_stack *stack);

// function to rotate stack a and stack b at the same time
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);

// function to reverse rotate stack a and b at the same time 
void	ft_rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);

// function to test the top node
void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

// function to initialize to nodes in b
void	ft_init_nodes_of_b(t_stack *stack_a, t_stack *stack_b);


// #________________functions for actions____________________#

void	pa(t_stack	**stack_a, t_stack **stack_b, bool to_print);
void	pb(t_stack **stack_a, t_stack **stack_b, bool to_print);
void	sa(t_stack **stack_a, bool to_print);
void	sb(t_stack **stack_b, bool to_print);
void	ss(t_stack **stack_a, t_stack **stack_b, bool to_print);
void	ra(t_stack **stack_a, bool to_print);
void	rb(t_stack **stack_b, bool to_print);
void	rr(t_stack	**stack_a, t_stack **stack_b, bool to_print);
void	rra(t_stack **stack_a, bool to_print);
void	rrb(t_stack **stack_b, bool to_print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool to_print);

// #________________functions for actions____________________#


#endif