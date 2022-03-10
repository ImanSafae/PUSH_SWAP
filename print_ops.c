/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:44:17 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/08 18:45:12 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_last_op(t_list *ops)
{
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

void	check_rr(t_list **ops)
{
	if ((((*ops)->content == RA && (*ops)->next->content == RB))
		|| ((*ops)->content == RB && (*ops)->next->content == RA))
	{
		(*ops) = (*ops)->next;
		ft_putstr_fd("rr\n", 1);
	}
	else if ((*ops)->content == RA)
		ft_putstr_fd("ra\n", 1);
	else if ((*ops)->content == RB)
		ft_putstr_fd("rb\n", 1);
}

void	check_ss(t_list **ops)
{
	if ((((*ops)->content == SA && (*ops)->next->content == SB))
		|| ((*ops)->content == SB && (*ops)->next->content == SA))
	{
		(*ops) = (*ops)->next;
		ft_putstr_fd("ss\n", 1);
	}
	else if ((*ops)->content == SA)
		ft_putstr_fd("sa\n", 1);
	else if ((*ops)->content == SB)
		ft_putstr_fd("sb\n", 1);
}

void	check_rrr(t_list **ops)
{
	if ((((*ops)->content == RRA && (*ops)->next->content == RRB))
		|| ((*ops)->content == RRB && (*ops)->next->content == RRA))
	{
		(*ops) = (*ops)->next;
		ft_putstr_fd("rrr\n", 1);
	}
	else if ((*ops)->content == RRA)
		ft_putstr_fd("rra\n", 1);
	else if ((*ops)->content == RRB)
		ft_putstr_fd("rrb\n", 1);
}

void	check_useless_ops(t_list **ops)
{
	if ((*ops)->content == RA && (*ops)->next->content == RRA)
		(*ops) = (*ops)->next;
	else if ((*ops)->content == RB && (*ops)->next->content == RRB)
		(*ops) = (*ops)->next;
	else if ((*ops)->content == RRA && (*ops)->next->content == RA)
		(*ops) = (*ops)->next;
	else if ((*ops)->content == RRB && (*ops)->next->content == RB)
		(*ops) = (*ops)->next;
}
