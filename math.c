/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:13:22 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/08 23:13:23 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_list *stack, int size)
{
	int	rank;
	int	*tab;

	tab = list_to_sorted_tab(stack, size);
	rank = (size / 2);
	return (tab[rank - 1]);
}

// int	get_tridian(t_list *stack, int index, int size)
// {
// 	int	rank;
// 	int	*tab;

// 	tab = list_to_sorted_tab(stack, size);
// 	rank = (size / 3) * index;
// 	return (tab[rank - 1]);
// }
