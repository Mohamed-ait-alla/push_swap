/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:16 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/06 12:11:31 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_stack_len(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	sa(t_stack **stack_a, bool to_print)
{
	ft_swap(stack_a);
	if (!to_print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, bool to_print)
{
	ft_swap(stack_b);
	if (!to_print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool to_print)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (!to_print)
		write(1, "ss\n", 3);
}
