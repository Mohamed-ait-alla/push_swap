/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:26 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/03 17:48:30 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h> // we don't need it when we gonna push that shit
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

// we don't need this function when we gonna push this shit //
void	ft_display(t_stack *stack);

//***Stack initialazation
t_stack	*ft_new_node(int value);
void	ft_append_node(t_stack **stack, t_stack *new);
void	ft_init_stack_a(int argc, char	**argv, t_stack **stack_a);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);

//***Handle errors
int		ft_check_duplicates(t_stack *stack, int value);
int		ft_check_for_non_integers(const char *s);
int		ft_check_error(char	*argv, t_stack	*stack_a);

//***Free memory
void	ft_free_stack(t_stack **stack);
void	ft_free_splited(char **splited);

//***Nodes intialazation
void	ft_init_nodes_of_a(t_stack *stack_a, t_stack *stack_b);
void	ft_current_index(t_stack *stack);
void	ft_set_cheapest(t_stack *stack);
void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
t_stack	*ft_get_cheapest_node(t_stack *stack);

//***Stack utils
t_stack	*ft_find_biggest_node(t_stack *stack);
t_stack	*ft_find_smallest_node(t_stack *stack);
bool	ft_is_sorted(t_stack *stack);
int		ft_stack_len(t_stack *stack);
int		ft_max(int a, int b);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_get_last(t_stack *stack);

//***Rules
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

//***Helper rules
void	ft_rotate_both(t_stack **stack_a,
			t_stack **stack_b,
			t_stack *cheapest_node);
void	ft_rev_rotate_both(t_stack **stack_a,
			t_stack **stack_b,
			t_stack *cheapest_node);

//***Algorithm
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b);

#endif