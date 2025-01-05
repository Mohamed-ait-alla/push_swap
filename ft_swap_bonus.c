/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:48:33 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/05 09:55:26 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_swap(t_stack **stack)
{
	t_stack *tmp;

	if (ft_stack_len(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	sa(t_stack **stack_a)
{
	ft_swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	ft_swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}