/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:39:56 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:40:00 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, t_list **ops)
{
	int	tmp;

	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
	// ft_putstr_fd("sa\n", 1);
	ft_lstadd_back(ops, ft_lstnew(SA));
}

void	sb(t_list **stack_b, t_list **ops)
{
	int	tmp;

	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
	// ft_putstr_fd("sb\n", 1);
	ft_lstadd_back(ops, ft_lstnew(SB));
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

void	pa(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	// ft_putstr_fd("pa\n", 1);
	ft_lstadd_back(ops, ft_lstnew(PA));
}

void	pb(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	// ft_putstr_fd("pb\n", 1);
	ft_lstadd_back(ops, ft_lstnew(PB));
}

void	ra(t_list **stack_a, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	// ft_putstr_fd("ra\n", 1);
	ft_lstadd_back(ops, ft_lstnew(RA));
}

void	rb(t_list **stack_b, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
	// ft_putstr_fd("rb\n", 1);
	ft_lstadd_back(ops, ft_lstnew(RB));
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

void	rra(t_list **stack_a, t_list **ops)
{
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
	// ft_putstr_fd("rra\n", 1);
	ft_lstadd_back(ops, ft_lstnew(RRA));
}

void	rrb(t_list **stack_b, t_list **ops)
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
	// ft_putstr_fd("rrb\n", 1);
	ft_lstadd_back(ops, ft_lstnew(RRB));
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

void	print_operations(t_list *ops)
{
	while (ops->next)
	{
		if (ops->content == SA)
		{
			if (ops->next->content == SB)
			{
				ft_putstr_fd("ss\n", 1);
				ops = ops->next;
			}
			else
				ft_putstr_fd("sa\n", 1);
		}
		else if (ops->content == SB)
			{
			if (ops->next->content == SA)
			{
				ft_putstr_fd("ss\n", 1);
				ops = ops->next;
			}
			else
				ft_putstr_fd("sb\n", 1);
		}
		else if (ops->content == PA)
			ft_putstr_fd("pa\n", 1);
		else if (ops->content == PB)
			ft_putstr_fd("pb\n", 1);
		else if (ops->content == RA)
		{
			if (ops->next->content == RRA)
				ops = ops->next;
			else if (ops->next->content == RB)
			{
				ft_putstr_fd("rr\n", 1);
				ops = ops->next;
			}
			else
				ft_putstr_fd("ra\n", 1);
		}
		else if (ops->content == RB)
		{
			if (ops->next->content == RRB)
				ops = ops->next;
			else if (ops->next->content == RA)
			{
				ft_putstr_fd("rr\n", 1);
				ops = ops->next;
			}
			else
				ft_putstr_fd("rb\n", 1);
		}
		else if (ops->content == RRA)
		{
			if (ops->next->content == RA)
				ops = ops->next;
			else if (ops->next->content == RRB)
			{
				ft_putstr_fd("rrr\n", 1);
				ops = ops->next;
			}
			else
				ft_putstr_fd("rra\n", 1);
		}
		else if (ops->content == RRB)
		{
			if (ops->next->content == RB)
				ops = ops->next;
			else if (ops->next->content == RRA)
			{
				ft_putstr_fd("rrr\n", 1);
				ops = ops->next;
			}
			else
				ft_putstr_fd("rrb\n", 1);
		}
		if (ops->next)
			ops = ops->next;
	}
	if (ops->content == SA)
			ft_putstr_fd("sa\n", 1);
	else if (ops->content == SB)
		ft_putstr_fd("sb\n", 1);
	else if (ops->content == PA)
		ft_putstr_fd("pa\n", 1);
	else if (ops->content == PB)
		ft_putstr_fd("pb\n", 1);
	else if (ops->content == RA)
		ft_putstr_fd("ra\n", 1);
	else if (ops->content == RB)
		ft_putstr_fd("rb\n", 1);
	else if (ops->content == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (ops->content == RRB)
		ft_putstr_fd("rrb\n", 1);
}
