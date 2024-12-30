/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:56 by mait-all          #+#    #+#             */
/*   Updated: 2024/12/30 17:57:09 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_1;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp_1 = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	*stack = last;
	last->next = tmp_1;
}

void	rra(t_stack **stack_a, bool to_print)
{
	ft_reverse_rotate(stack_a);
	if (!to_print)
		printf("rra\n");
}

void	rrb(t_stack **stack_b, bool to_print)
{
	ft_reverse_rotate(stack_b);
	if (!to_print)
		printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool to_print)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (!to_print)
		printf("rrr\n");
}

void	ft_rev_rotate_both(t_stack **stack_a,
							t_stack **stack_b,
							t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rrr(stack_a, stack_b, false);
	ft_current_index(*stack_a);
	ft_current_index(*stack_b);
}
