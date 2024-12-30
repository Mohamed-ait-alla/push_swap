/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:49 by mait-all          #+#    #+#             */
/*   Updated: 2024/12/30 17:57:55 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack);
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	ra(t_stack **stack_a, bool to_print)
{
	ft_rotate(stack_a);
	if (!to_print)
		printf("ra\n");
}

void	rb(t_stack **stack_b, bool to_print)
{
	ft_rotate(stack_b);
	if (!to_print)
		printf("rb\n");
}

void	rr(t_stack	**stack_a, t_stack **stack_b, bool to_print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (!to_print)
		printf("rr\n");
}

void	ft_rotate_both(t_stack **stack_a,
						t_stack **stack_b,
						t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b, false);
	ft_current_index(*stack_a);
	ft_current_index(*stack_b);
}
