#include "push_swap.h"

int	ft_stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
}

int ft_check_duplicates(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (0);
        stack = stack -> next;
    }
    return (1);
}

t_stack	*ft_find_biggest_node(t_stack *stack)
{
	t_stack *biggest_node;

	biggest_node = stack;
	stack = stack -> next;
	while (stack)
	{
		if (stack -> value > biggest_node -> value)
			biggest_node = stack;
		stack = stack -> next;
	}
	return (biggest_node);
}

t_stack	*ft_get_cheapest_node(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack -> next;
	}
}