/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:40:08 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/06 16:17:22 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*ft_get_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}

void	ft_append_node(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack)
	{
		if (stack[0])
		{
			last = ft_get_last(*stack);
			last->next = new;
		}
		else
			stack[0] = new;
	}
}

void	ft_init_stack_a(int argc, char	**argv, t_stack **stack_a)
{
	int		i;
	int		j;
	char	**splited;

	i = 0;
	while (++i < argc)
	{
		splited = ft_split(argv[i], ' ');
		j = 0;
		while (splited[j] || (!j && !splited[j]))
		{
			if (!ft_check_error(splited[j], *stack_a) || (!j && !splited[j]))
			{
				ft_free_splited(splited);
				ft_free_stack(stack_a);
				write(2, "Error\n", 6);
				exit(1);
			}
			ft_append_node(stack_a, ft_new_node((int)ft_atol(splited[j])));
			j++;
		}
		ft_free_splited(splited);
	}
}
