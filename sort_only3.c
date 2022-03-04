/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_only3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:40:50 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:40:51 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sa(t_list **stack, t_list **ops)
{
	int	top;
	int	middle;
	int	bottom;

	top = (int)((*stack)->content);
	middle = (int)((*stack)->next->content);
	bottom = (int)((*stack)->next->next->content);
	if (is_sorted((*stack)))
		return ;
	if (top < bottom && bottom < middle)
		sa(stack, ops);
	else if (bottom < middle && middle < top)
		sa(stack, ops);
	else if (middle < top && top < bottom)
		sa(stack, ops);
}

static void	check_ra(t_list **stack, t_list **ops)
{
	int	top;
	int	middle;
	int	bottom;

	top = (int)((*stack)->content);
	middle = (int)((*stack)->next->content);
	bottom = (int)((*stack)->next->next->content);
	if (is_sorted((*stack)))
		return ;
	if (middle < bottom && bottom < top)
		ra(stack, ops);
}

static void	check_rra(t_list **stack, t_list **ops)
{
	int	top;
	int	middle;
	int	bottom;

	top = (int)((*stack)->content);
	middle = (int)((*stack)->next->content);
	bottom = (int)((*stack)->next->next->content);
	if (is_sorted((*stack)))
		return ;
	if (bottom < top && top < middle)
		rra(stack, ops);
}

void	sort_two_or_three(t_list **stack, t_list **ops)
{
	if (ft_lstsize((*stack)) == 2)
	{
		if (!is_sorted((*stack)))
			sa(stack, ops);
		return ;
	}
	else if (ft_lstsize((*stack)) == 3)
	{
		while (!is_sorted((*stack)))
		{
			check_sa(stack, ops);
			check_ra(stack, ops);
			check_rra(stack, ops);
		}
	}
}
