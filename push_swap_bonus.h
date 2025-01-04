/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-all <mait-all@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:03:15 by mait-all          #+#    #+#             */
/*   Updated: 2025/01/04 12:37:07 by mait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "./get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

int		ft_check_error(char	*arg, t_stack	*stack_a);
void	ft_init_stack_a(int argc, char	**argv, t_stack **stack_a);
#endif