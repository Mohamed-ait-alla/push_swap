/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:03:15 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/12 15:45:29 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"

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


//***Stack initialazation
t_stack	*ft_get_last(t_stack *stack);
void	ft_append_node(t_stack **stack, t_stack *new);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);
void	ft_init_stack_a(int argc, char	**argv, t_stack **stack_a);

//***Free memory
void	ft_free_stack(t_stack **stack);
void	ft_free_splited(char **splited);

//***Handle errors
void	ft_error(char *action, t_stack **stack_a, t_stack **stack_b);
int		ft_check_error(char	*arg, t_stack	*stack_a);

//***Utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_stack_len(t_stack *stack);
size_t	ft_strlen(const char *s);
bool	ft_is_sorted(t_stack *stack);
void	ft_execute_action(char	*action, t_stack **stack_a, t_stack **stack_b);

//***Actions
void	pa(t_stack	**stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack	**stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//***Cases
bool	ft_push_case(char *action, t_stack **stack_a, t_stack **stack_b);
bool	ft_swap_case(char *action, t_stack **stack_a, t_stack **stack_b);
bool	ft_rotate_case(char *action, t_stack **stack_a, t_stack **stack_b);
bool	ft_rev_rotate_case(char *action, t_stack **stack_a, t_stack **stack_b);
#endif