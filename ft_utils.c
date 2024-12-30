#include "push_swap.h"


bool	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack -> value > stack -> next -> value)
			return (false);
		stack = stack -> next;
	}
	return (true);
}

// display a stack
void	ft_display(t_stack *stack)
{
	t_stack *tmp;

    tmp = stack;
    while (tmp)
    {
        printf("%d \n", tmp->value);
        tmp = tmp->next;

    }
}
