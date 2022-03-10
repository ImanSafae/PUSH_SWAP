/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:48:00 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/08 18:48:01 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	ft_lstadd_back(ops, ft_lstnew(RA));
}

void	rb(t_list **stack_b, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
	ft_lstadd_back(ops, ft_lstnew(RB));
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
	ft_lstadd_back(ops, ft_lstnew(RRB));
}

void	print_operations(t_list *ops)
{
	while (ops->next)
	{
		if (ops->content == SA || ops->content == SB)
			check_ss(&ops);
		else if (ops->content == PA)
			ft_putstr_fd("pa\n", 1);
		else if (ops->content == PB)
			ft_putstr_fd("pb\n", 1);
		else if (ops->content == RA || ops->content == RB)
		{
			check_useless_ops(&ops);
			check_rr(&ops);
		}
		else if (ops->content == RRA || ops->content == RRB)
		{
			check_useless_ops(&ops);
			check_rrr(&ops);
		}
		if (ops->next)
			ops = ops->next;
	}
	print_last_op(ops);
}
