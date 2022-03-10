/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:55:32 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/08 18:55:33 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->next->content < stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_tab(int **tab, int limit)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i + 1 < limit)
	{
		if ((*tab)[i] > (*tab)[i + 1])
		{
			tmp = (*tab)[i];
			(*tab)[i] = (*tab)[i + 1];
			(*tab)[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	*put_list_in_tab(t_list *stack, int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * (size + 1));
	i = 0;
	while (i < size)
	{
		tab[i] = stack->content;
		i++;
		stack = stack->next;
	}
	return (tab);
}

int	*list_to_sorted_tab(t_list *stack, int size)
{
	int	*tab;

	tab = put_list_in_tab(stack, size);
	sort_tab(&tab, size);
	return (tab);
}
