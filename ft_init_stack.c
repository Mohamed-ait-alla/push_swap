#include "push_swap.h"

t_stack *ft_new_node(int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}


static void	ft_append_node(t_stack **stack, int value)
{
    t_stack *new;

    new = ft_new_node(value);
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
        ft_append_node(stack_a, (int)n);
        i++;
	}
}