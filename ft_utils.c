#include "push_swap.h"

void	ft_del_one(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
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