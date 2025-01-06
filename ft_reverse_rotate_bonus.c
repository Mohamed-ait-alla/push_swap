/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:48:29 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/06 12:19:27 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
