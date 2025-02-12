/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:40:03 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/12 15:17:35 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

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

void	pa(t_stack	**stack_a, t_stack **stack_b, bool to_print)
{
	ft_push(stack_a, stack_b);
	if (!to_print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool to_print)
{
	ft_push(stack_a, stack_b);
	if (!to_print)
		write(1, "pb\n", 3);
}
