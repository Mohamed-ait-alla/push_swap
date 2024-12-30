/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:56 by mait-all          #+#    #+#             */
/*   Updated: 2024/12/30 18:04:16 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_init_stack_a(&stack_a, argv);
	}
	else
		ft_init_stack_a(&stack_a, argv + 1);
	if (!ft_is_sorted(stack_a))
	{
		if (ft_stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (ft_stack_len(stack_a) == 3)
			ft_sort_three(&stack_a);
		else
			ft_sort_stacks(&stack_a, &stack_b);
	}
	printf("-------------------after sort------------------------\n");
	ft_display(stack_a);
	printf("- -\na b\n");
	ft_free_stack(&stack_a);
}
