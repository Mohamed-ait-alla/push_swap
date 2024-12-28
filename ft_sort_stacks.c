#include "push_swap.h"

static void	ft_move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_get_cheapest_node(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		ft_rev_rotate_both(stack_a, stack_b, false);
	ft_prep_for_push(stack_a, cheapest_node, 'a');
	ft_prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a, false);
}

static void	ft_move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, false);
}

static void	ft_set_min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->value != ft_find_smallest_node(*stack_a)->value)
	{
		if (ft_find_smallest_node(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = ft_find_biggest_node(*stack_a);
	if (biggest_node == *stack_a)
		ft_rotate(stack_a);
	else if (biggest_node == (*stack_a)->next)
		ft_reverse_rotate(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap(stack_a);
}

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = ft_stack_len(*stack_a);
	if (len_a-- > 3 && !ft_is_sorted(*stack_a))
		ft_push(&stack_b, &stack_a);
	if (len_a-- > 3 && !ft_is_sorted(*stack_a))
		ft_push(&stack_b, &stack_a);
	while (len_a-- > 3 && !ft_is_sorted(*stack_a))
	{
		ft_init_nodes_of_a(*stack_a, *stack_b);
		ft_move_a_to_b(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_init_nodes_of_b(*stack_a, *stack_b);
		ft_move_b_to_a(stack_a, stack_b);
	}
	ft_current_index(*stack_a);
	ft_set_min_on_top(stack_a);
}