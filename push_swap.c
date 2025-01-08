/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:56 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/07 15:13:32 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	ft_init_stack_a(argc, argv, &stack_a);
	if (!ft_is_sorted(stack_a))
	{
		if (ft_stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (ft_stack_len(stack_a) == 3)
			ft_sort_three(&stack_a);
		else if (ft_stack_len(stack_a) == 5)
			ft_sort_five(&stack_a, &stack_b);
		else
			ft_sort_stacks(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	return (0);
}
