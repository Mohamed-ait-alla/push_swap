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
    printf("before r_rotate\n");
	printf("-------------------------------------------\n");
    t_stack *tmp;
	t_stack *tmp_1;

    tmp = stack_a;
	tmp_1 = stack_b;
    while (tmp)
    {
        printf("%d ", tmp->value);
		
		if (tmp_1)
		{
			printf("%d\n", tmp_1->value);
				tmp_1 = tmp_1->next;
		}
		else
			printf("\n");
        tmp = tmp->next;

    }
	printf("- -\na b\n");
	printf("-------------------------------------------\n");
    // ft_reverse_rotate_a(&stack_a);
    // printf("\nafter r_rotate\n");
	// tmp = stack_a;
	// // tmp_1 = stack_b;
    // while (tmp)
    // {
	// 	printf("%d %d\n", tmp->value);
	// 	tmp = tmp->next;
	// 	// tmp_1 = tmp_1->next;
    // }
	// printf("- -\na b");
}