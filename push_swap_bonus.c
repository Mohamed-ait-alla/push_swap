/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:02:39 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/05 11:19:53 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*action;

	stack_a = NULL;
	stack_b = NULL;
	action = NULL;
	if (argc == 1)
		return (0);
	ft_init_stack_a(argc, argv, &stack_a);
	action = get_next_line(0);
	while (action)
	{
		ft_execute_action(action, &stack_a, &stack_b);
		free(action);
		action = get_next_line(0);
	}
	if (ft_is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(action);
}

void	ft_execute_action(char	*action, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_push_case(action, stack_a, stack_b))
		if (!ft_swap_case(action, stack_a, stack_b))
			if (!ft_rotate_case(action, stack_a, stack_b))
				if (!ft_rev_rotate_case(action, stack_a, stack_b))
					ft_error(action);
}

void	ft_error(char *action)
{
	free(action);
	write(2, "Error\n", 6);
	exit(1);
}