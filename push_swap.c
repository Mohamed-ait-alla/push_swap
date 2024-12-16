#include "push_swap.h"


long	ft_atoi(const char *str)
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

int ft_check_for_non_integers(const char *s)
{
    while (*s)
    {
        if (*s < 48 || *s > 57)
            return (0);
        s++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int     i;
    long    n;
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc == 1)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while(i < argc)
    {
        n = ft_atoi(argv[i]);
        if (n > INT_MAX || n < INT_MIN || !ft_check_duplicates(stack_a, n) || !ft_check_for_non_integers(argv[i]))
        {
            write(2, "Error\n", 6);
            return 0;
        }
        push(&stack_a, n);
        i++;
    }
    // display the stack
    while (stack_a)
    {
        printf("%d  ", stack_a->value);
        stack_a = stack_a->next;
    }
}