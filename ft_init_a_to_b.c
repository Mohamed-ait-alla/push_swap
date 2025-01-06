/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:40:26 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/06 12:38:35 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_cost_analysis_logic(t_stack *stack_a, int len_a, int len_b)
{
	if (stack_a->above_median
		&& stack_a->target_node->above_median)
		stack_a->push_cost = ft_max(stack_a->index,
				stack_a->target_node->index);
	else if (!stack_a->above_median
		&& !stack_a->target_node->above_median)
		stack_a->push_cost = ft_max(len_a - stack_a->index,
				len_b - stack_a->target_node->index);
	else
	{
		if (stack_a->above_median)
			stack_a->push_cost = stack_a->index
				+ (len_b - stack_a->target_node->index);
		else
			stack_a->push_cost = stack_a->target_node->index
				+ (len_a - stack_a->index);
	}
}

static void	ft_set_target_node_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b -> next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = ft_find_biggest_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a -> next;
	}
}

static void	ft_calc_cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_a)
	{
		ft_cost_analysis_logic(stack_a, len_a, len_b);
		stack_a = stack_a -> next;
	}
}

void	ft_set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		else
			stack->cheapest = false;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_init_nodes_of_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_current_index(stack_a);
	ft_current_index(stack_b);
	ft_set_target_node_a(stack_a, stack_b);
	ft_calc_cost_analysis_a(stack_a, stack_b);
	ft_set_cheapest(stack_a);
}
