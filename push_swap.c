#include "push_swap.h"

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
	ft_sort_stacks(&stack_a, &stack_b);
	printf("-------------------------------------------\n");
    t_stack *tmp;

    tmp = stack_a;
    while (tmp)
    {
        printf("%d \n", tmp->value);
        tmp = tmp->next;

    }
	printf("- -\na b\n");

}