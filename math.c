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
	int	median;

	tab = list_to_sorted_tab(stack, size);
	rank = (size / 2);
	median = tab[rank - 1];
	free(tab);
	return (median);
}
