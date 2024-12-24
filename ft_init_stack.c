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