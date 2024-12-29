#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current -> next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}