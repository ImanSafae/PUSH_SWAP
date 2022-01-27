#include "push_swap.h"

void    swap(t_list **stack, char a_or_b)
{
    t_list  *pointer;

    if (!stack || ft_lstsize(stack) <= 1)
        return ;
    if (ft_lstsize(stack) == 2)
    {
        pointer = (*stack)->next;
        (*stack)->next = NULL;
        pointer->next = (*stack);
    }
    else
    {
        pointer = (*stack)->next;
        (*stack) = pointer->next;
        pointer->next = (*stack);
    }
    if (a_or_b == 'a')
        ft_putstr_fd("sa\n", 1);
    else if (a_or_b == 'b')
        ft_putstr_fd("sb\n", 1);
}

void    push(t_list **origin, t_list **dest, char a_or_b)
{
	t_list	*pointer;

	if (!(*origin))
		return ;
	pointer = (*origin)->next;
	// (*origin)->next = NULL;
	ft_lstadd_front(dest, *origin);
	*origin = pointer;
    if (a_or_b == 'a')
        ft_putstr_fd("pa\n", 1);
    else if (a_or_b == 'b')
        ft_putstr_fd("pb\n", 1);
}

void	rotate(t_list **stack, char a_or_b)
{
	t_list	*last;

 
	last = ft_lstlast(*stack);

}