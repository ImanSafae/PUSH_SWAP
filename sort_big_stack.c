/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:40:42 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:40:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_chunks_list(t_list **chunks, int count)
{
	t_list	*tmp;

	if (count == 0)
	{
		tmp = (*chunks);
		(*chunks) = (*chunks)->next;
		free(tmp);
	}
	else
		(*chunks)->content = count;
}

void	init_stack_info(t_list *stack, t_info **info, int size)
{
	(*info) = malloc(sizeof(t_info));
	(*info)->stack_size = size;
	(*info)->median = get_median(stack, size);
}

void	divide_a_by_median(t_list **a, t_list **b, t_moves **moves, int size)
{
	t_info	*info;
	int		i;
	int		count;

	init_stack_info((*a), &info, size);
	i = 0;
	count = 0;
	while (i < info->stack_size)
	{
		if ((*a)->content > info->median)
			ra(a, &(*moves)->ops);
		else
		{
			pb(a, b, &(*moves)->ops);
			count++;
		}
		i++;
	}
	free(info);
	ft_lstadd_front(&(*moves)->chunks, ft_lstnew(count));
}

static int	divide_b(t_info **info, t_list **a, t_list **b, t_list **ops)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < (*info)->stack_size)
	{
		if ((*b)->content > (*info)->median)
			pa(a, b, ops);
		else
		{
			rb(b, ops);
			count++;
		}
		i++;
	}
	i = 0;
	while (i < count)
	{
		rrb(b, ops);
		i++;
	}
	return (count);
}

int	divide_b_by_median(t_list **b, t_list **a, t_list **chunks, t_list **ops)
{
	t_info	*info;
	int		count;
	int		ret;

	init_stack_info((*b), &info, (*chunks)->content);
	count = 0;
	ret = (*chunks)->content;
	count = divide_b(&info, a, b, ops);
	free(info);
	update_chunks_list(chunks, count);
	return (ret - count);
}
