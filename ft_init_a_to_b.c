#include "push_swap.h"


void	ft_current_index(t_stack *stack)
{
	int	i;
	int median;

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

static void	ft_set_target_node_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value 
					&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b -> next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = ft_find_biggest_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a -> next;
	}

}

static void	ft_calc_cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - stack_a->index;
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - stack_a->target_node->index;
		stack_a = stack_a -> next;
	}
}

void	ft_set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
	
}

void	ft_init_nodes_of_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_current_index(stack_a);
	ft_current_index(stack_b);
	ft_set_target_node_a(stack_a, stack_b);
	ft_calc_cost_analysis_a(stack_a, stack_b);
	ft_set_cheapest(stack_a);
}