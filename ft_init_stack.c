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

void	ft_init_stack_a(t_stack **stack_a, char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN || !ft_check_duplicates(*stack_a, (int)n) || !ft_check_for_non_integers(argv[i]))
        {
			ft_free_stack(stack_a);
			printf("Error\n");
            exit(1);
        }
        push(stack_a, (int)n);
        i++;
	}
}