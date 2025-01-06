/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:24:24 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/06 12:16:40 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
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

void	ft_execute_action(char	*action, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_push_case(action, stack_a, stack_b))
		if (!ft_swap_case(action, stack_a, stack_b))
			if (!ft_rotate_case(action, stack_a, stack_b))
				if (!ft_rev_rotate_case(action, stack_a, stack_b))
					ft_error(action);
}
