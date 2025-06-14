/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:22:40 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/05 11:32:39 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap_bonus.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_check_for_non_integers(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && i == 0 && ft_isdigit(s[i + 1]))
			i++;
		else if (s[i] == '+' && i == 0 && ft_isdigit(s[i + 1]))
			i++;
		else if (s[i] < 48 || s[i] > 57)
			return (0);
		else
			i++;
	}
	return (1);
}

static int	ft_check_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

int	ft_check_error(char	*arg, t_stack	*stack_a)
{
	long	n;

	if (!arg)
		return (0);
	n = ft_atol(arg);
	if (n > INT_MAX || n < INT_MIN
		|| !ft_check_duplicates(stack_a, (int)n)
		|| !ft_check_for_non_integers(arg) || arg[0] == '\0')
		return (0);
	return (1);
}

void	ft_error(char *action, t_stack **stack_a, t_stack **stack_b)
{
	free(action);
	get_next_line(-2);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
