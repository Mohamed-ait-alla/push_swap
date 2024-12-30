/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:40:16 by mait-all          #+#    #+#             */
/*   Updated: 2024/12/30 17:48:23 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_target_node_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a -> next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = ft_find_smallest_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b -> next;
	}
}

void	ft_init_nodes_of_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_current_index(stack_a);
	ft_current_index(stack_b);
	ft_set_target_node_b(stack_a, stack_b);
}
