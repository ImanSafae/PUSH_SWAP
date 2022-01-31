#include "push_swap.h"

void	sa(t_list **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = &tmp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = &tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	int	tmp;

	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = &tmp;
	ft_putstr_fd("sa\n", 1);
}