/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:48:41 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/12 15:19:55 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap_bonus.h"

static void	ft_push(t_stack **dest, t_stack **source)
{
	t_stack	*new;

	if (ft_stack_len(*source) > 0)
	{
		new = *source;
		*source = (*source)->next;
		new->next = *dest;
		*dest = new;
	}
}

void	pa(t_stack	**stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
}
