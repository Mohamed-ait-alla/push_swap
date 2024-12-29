#include "push_swap.h"

void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	t_stack *new;

	if (!*stack_b)
		return ;
	value = (*stack_b)->value;
	new = new_node(value);
	new->next = *stack_a;
	*stack_a = new;
	ft_del_one(stack_b);
}

void	pa(t_stack	**stack_a, t_stack **stack_b, bool to_print)
{
	ft_push(stack_a, stack_b);
	if (!to_print)
		printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool to_print)
{
	ft_push(stack_a, stack_b);
	if (!to_print)
		printf("pb\n");
}
