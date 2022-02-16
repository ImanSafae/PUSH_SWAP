#include "push_swap.h"

void	sa(t_list **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	int	tmp;
	int	tmp2;

	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
	tmp2 = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp2;
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	ft_putstr_fd("ra\n", 1);

	/* méthode alternative ?
	int		first;
	t_list	*tmp;

	first = (*stack_a)->content;
	tmp = *stack_a;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = &first; */
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	tmp2 = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp2);
	tmp2->next = NULL;
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_list **stack_a)
{
	// int		*tmp1;
	// int		*tmp2;
	// t_list	*tmp;

	// tmp = *stack_a;
	// tmp1 = tmp->content;
	// tmp->content = (ft_lstlast(*stack_a))->content;
	// tmp = tmp->next;
	// while (tmp->next)
	// {
	// 	tmp2 = tmp->next->content;
	// 	tmp->content = tmp1;
	// 	tmp1 = tmp2;
	// 	tmp = tmp->next;
	// }
	// ft_putstr_fd("rra\n", 1);

	/* méthode alternative*/ 
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_a);
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("rra\n", 1);
}


void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	
	tmp = (*stack_b);
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
	t_list	*tmp4;

	tmp = (*stack_a);
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	tmp3 = (*stack_b);
	while (tmp3->next)
	{
		tmp4 = tmp3;
		tmp3 = tmp3->next;
	}
	tmp4->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("rrr\n", 1);
}