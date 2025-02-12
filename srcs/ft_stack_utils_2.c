/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:08 by mait-all          #+#    #+#             */
/*   Updated: 2025/02/12 15:15:23 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack -> value > stack -> next -> value)
			return (false);
		stack = stack -> next;
	}
	return (true);
}

void	ft_current_index(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack -> next;
		i++;
	}
}

// display a stack
void	ft_display(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d \n", tmp->value);
		tmp = tmp->next;
	}
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new == NULL)
		return ;
	if (lst)
	{
		if (lst[0])
			new->next = lst[0];
		lst[0] = new;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
