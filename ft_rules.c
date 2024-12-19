#include "push_swap.h"


t_stack *new_node(int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}

void    push(t_stack **stack, int value)
{
    t_stack *new;

    new = new_node(value);
    if (!(*stack))
        (*stack) = new;
    else
    {
        t_stack *current = *stack;
        while(current->next)
            current = current->next;
        current->next = new;
    }
}

int	check_for_empty_stack(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
 		count++;
	}
	if (count == 1 || count == 0)
		return (0);
	return (1);
}

void	ft_swap_a(t_stack **stack_a)
{
    int tmp;

    if (!check_for_empty_stack(*stack_a))
        return ;
    tmp = ((*stack_a)->value);
    (*stack_a)->value = (*stack_a)->next->value;
    (*stack_a)->next->value = tmp;
}

void	ft_swap_b(t_stack **stack_b)
{
	int	tmp;

	if (!check_for_empty_stack(*stack_b))
		return ;
	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;
}

void	ft_swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
}

void	ft_push_a(t_stack *stack_b, t_stack **stack_a)
{
	push(stack_a, stack_b->value);
}

void	ft_push_b(t_stack *stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a->value);
}

void	ft_rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*tmp;

	first = (*stack_a);
	tmp = (*stack_a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*stack_a = first->next;
	first->next = NULL;
}

void	ft_rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack *tmp;

	first = *stack_b;
	tmp = *stack_b;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*stack_b = first->next;
	first->next = NULL;
}

void	ft_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp_1;
	t_stack *last;

	tmp = *stack_a;
	tmp_1 = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	*stack_a = last;
	last->next = tmp_1;
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack *tmp_1;
	t_stack	*last;

	tmp = *stack_b;
	tmp_1 = *stack_b;
	while (tmp->next->next)
		tmp = tmp ->next;
	last = tmp->next;
	tmp->next = NULL;
	*stack_b = last;
	last->next = tmp_1;	
}

void	ft_reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_a(stack_a);
	ft_reverse_rotate_b(stack_b);
}