#include "push_swap.h"


void	ft_swap(t_stack **stack)
{
    int tmp;

    if (!check_for_empty_stack(*stack))
        return ;
    tmp = ((*stack)->value);
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
}

void	ft_swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	t_stack *new;

	if (!*stack_a || !*stack_b)
		return ;
	value = (*stack_b)->value;
	new = new_node(value);
	new->next = *stack_a;
	*stack_a = new;
	ft_del_one(stack_b);
}

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

void	ft_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
