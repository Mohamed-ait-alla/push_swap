/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:56 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/06 12:14:30 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_stack_len(*stack) > 1)
	{
		tmp = *stack;
		last = ft_get_last(*stack);
		while (tmp->next != last)
			tmp = tmp -> next;
		tmp -> next = NULL;
		ft_lstadd_front(stack, last);
	}
}

void	rra(t_stack **stack_a, bool to_print)
{
	ft_reverse_rotate(stack_a);
	if (!to_print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, bool to_print)
{
	ft_reverse_rotate(stack_b);
	if (!to_print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool to_print)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (!to_print)
		write(1, "rrr\n", 4);
}

void	ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *top)
{
	while (*a != top && *b != top->target_node)
	{
		rrr(a, b, false);
		ft_current_index(*a);
		ft_current_index(*b);
	}
}
