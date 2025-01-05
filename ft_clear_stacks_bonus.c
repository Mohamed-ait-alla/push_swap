/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_stacks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:23:51 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/05 11:24:04 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current -> next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
}
