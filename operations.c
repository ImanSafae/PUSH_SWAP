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
	ft_lstadd_back(ops, ft_lstnew(SA));
}

void	sb(t_list **stack_b, t_list **ops)
{
	int	tmp;

	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
	ft_lstadd_back(ops, ft_lstnew(SB));
}

void	pa(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	ft_lstadd_back(ops, ft_lstnew(PA));
}

void	pb(t_list **stack_a, t_list **stack_b, t_list **ops)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	ft_lstadd_back(ops, ft_lstnew(PB));
}
