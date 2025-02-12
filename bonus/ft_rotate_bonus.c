/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:48:37 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/12 15:20:02 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap_bonus.h"

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

void	ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
}

void	rr(t_stack	**stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
