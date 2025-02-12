/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:29:02 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/12 15:19:35 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap_bonus.h"

bool	ft_push_case(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(action, "pa\n", ft_strlen(action)) == 0)
	{
		pa(stack_a, stack_b);
		return (true);
	}
	else if (ft_strncmp(action, "pb\n", ft_strlen(action)) == 0)
	{
		pb(stack_b, stack_a);
		return (true);
	}
	return (false);
}

bool	ft_swap_case(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(action, "sa\n", ft_strlen(action)) == 0)
	{
		sa(stack_a);
		return (true);
	}
	else if (ft_strncmp(action, "sb\n", ft_strlen(action)) == 0)
	{
		sb(stack_b);
	}
	else if (ft_strncmp(action, "ss\n", ft_strlen(action)) == 0)
	{
		ss(stack_a, stack_b);
		return (true);
	}
	return (false);
}

bool	ft_rotate_case(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(action, "ra\n", ft_strlen(action)) == 0)
	{
		ra(stack_a);
		return (true);
	}
	else if (ft_strncmp(action, "rb\n", ft_strlen(action)) == 0)
	{
		rb(stack_b);
		return (true);
	}
	else if (ft_strncmp(action, "rr\n", ft_strlen(action)) == 0)
	{
		rr(stack_a, stack_b);
		return (true);
	}
	return (false);
}

bool	ft_rev_rotate_case(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(action, "rra\n", ft_strlen(action)) == 0)
	{
		rra(stack_a);
		return (true);
	}
	else if (ft_strncmp(action, "rrb\n", ft_strlen(action)) == 0)
	{
		rrb(stack_b);
		return (true);
	}
	else if (ft_strncmp(action, "rrr\n", ft_strlen(action)) == 0)
	{
		rrr(stack_a, stack_b);
		return (true);
	}
	return (false);
}
