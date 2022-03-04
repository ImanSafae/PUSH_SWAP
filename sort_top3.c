/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:40:57 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:40:59 by itaouil          ###   ########.fr       */
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
	if (top > middle)
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
	if (middle > top && middle > bottom)
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
	if (top < middle && middle < bottom)
		rra(stack, ops);
}

void	sort_top_three(t_list **stack, t_list **ops)
{
	while (!is_sorted(*stack))
	{
		check_ra(stack, ops);
		check_sa(stack, ops);
		check_rra(stack, ops);
	}
}
