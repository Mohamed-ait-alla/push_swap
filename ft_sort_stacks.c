#include "push_swap.h"

static void	ft_move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_get_cheapest_node(*stack_a);
	
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
		
	}
}