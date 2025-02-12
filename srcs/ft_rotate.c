/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:49 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/12 15:17:29 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_stack_len(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp -> next = NULL;
		ft_append_node(stack, tmp);
	}
}

void	ra(t_stack **stack_a, bool to_print)
{
	ft_rotate(stack_a);
	if (!to_print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, bool to_print)
{
	ft_rotate(stack_b);
	if (!to_print)
		write(1, "rb\n", 3);
}

void	rr(t_stack	**stack_a, t_stack **stack_b, bool to_print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (!to_print)
		write(1, "rr\n", 3);
}

void	ft_rotate_both(t_stack **stack_a,
						t_stack **stack_b,
						t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
	{
		rr(stack_a, stack_b, false);
		ft_current_index(*stack_a);
		ft_current_index(*stack_b);
	}
}
