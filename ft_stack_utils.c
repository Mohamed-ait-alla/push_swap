/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:25 by mait-all          #+#    #+#             */
/*   Updated: 2024/12/30 18:00:54 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
}

t_stack	*ft_find_biggest_node(t_stack *stack)
{
	t_stack	*biggest_node;

	biggest_node = stack;
	stack = stack -> next;
	while (stack)
	{
		if (stack -> value > biggest_node -> value)
			biggest_node = stack;
		stack = stack -> next;
	}
	return (biggest_node);
}

t_stack	*ft_find_smallest_node(t_stack *stack)
{
	t_stack	*smallest_node;

	smallest_node = stack;
	stack = stack -> next;
	while (stack)
	{
		if (stack -> value < smallest_node -> value)
			smallest_node = stack;
		stack = stack -> next;
	}
	return (smallest_node);
}

t_stack	*ft_get_cheapest_node(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack -> next;
	}
	return (stack);
}

void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
