/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:40:03 by mait-all          #+#    #+#             */
/*   Updated: 2024/12/30 17:55:26 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **dest, t_stack **source)
{
	int		value;
	t_stack	*new;

	if (!*source)
		return ;
	value = (*source)->value;
	new = ft_new_node(value);
	new->next = *dest;
	*dest = new;
	ft_del_one(source);
}

void	pa(t_stack	**stack_a, t_stack **stack_b, bool to_print)
{
	ft_push(stack_a, stack_b);
	if (!to_print)
		printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool to_print)
{
	ft_push(stack_a, stack_b);
	if (!to_print)
		printf("pb\n");
}
