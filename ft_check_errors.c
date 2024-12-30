#include "push_swap.h"

int ft_check_for_non_integers(const char *s)
{
	int	i;

	i = 0;
    while (s[i])
    {
		if (s[i] == '-' && i == 0)
			i++;
        else if (s[i] < 48 || s[i] > 57)
            return (0);
		else
        	i++;
    }
    return (1);
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