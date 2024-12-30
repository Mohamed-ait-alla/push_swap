#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	int tmp;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = ((*stack)->value);
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
}

void	sa(t_stack **stack_a, bool to_print)
{
	ft_swap(stack_a);
	if (!to_print)
		printf("sa\n");
}

void	sb(t_stack **stack_b, bool to_print)
{
	ft_swap(stack_b);
	if (!to_print)
		printf ("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool to_print)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (!to_print)
		printf("ss\n");
}