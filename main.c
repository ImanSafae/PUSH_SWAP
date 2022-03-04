/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:39:41 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:39:45 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b = 0;
	t_list	*chunks = 0;
	t_list	*ops;
	int		count;
	int		i;

	a = parse_list(argc, argv);
	i = 0;
	while (ft_lstsize(a) > 3)
		divide_a_by_median(&a, &b, &chunks, ft_lstsize(a), &ops);
	if (ft_lstsize(a) <= 3)
		sort_two_or_three(&a, &ops);
	while (chunks || !is_sorted(a))
	{
		if (chunks->content <= 3)
		{
			while (i < chunks->content)
			{
				pa(&a, &b, &ops);
				i++;
			}
			i = 0;
			chunks = chunks->next;
		}
		else
		{
			count = divide_b_by_median(&b, &a, &chunks, &ops);
			if (count > 3)
				divide_a_by_median(&a, &b, &chunks, count, &ops);
		}
		sort_top_three(&a, &ops);
	}
	print_operations(ops);
}
