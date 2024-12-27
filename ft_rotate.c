#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;

	first = (*stack);
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	ra(t_stack **stack_a, bool to_print)
{
	ft_rotate(stack_a);
	if (!to_print)
		printf("ra\n");
}

void	rb(t_stack **stack_b, bool to_print)
{
	ft_rotate(stack_b);
	if (!to_print)
		printf("rb\n");
}

void	rr(t_stack	**stack_a, t_stack **stack_b, bool to_print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (!to_print)
		printf("rr\n");
}