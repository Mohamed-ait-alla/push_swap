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
    printf("before r_rotate\n");
    t_stack *tmp;

    tmp = stack_a;
    while (tmp)
    {
        printf("%d  ", tmp->value);
        tmp = tmp->next;
    }
    ft_reverse_rotate_a(&stack_a);
    printf("\nafter r_rotate\n");
	tmp = stack_a;
    while (tmp)
    {
		printf("%d  ", tmp->value);
		tmp = tmp->next;
    }
}