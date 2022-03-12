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

static void	init_struct(t_moves **moves)
{
	t_list	*chunks;
	t_list	*ops;

	chunks = 0;
	ops = 0;
	(*moves)->chunks = chunks;
	(*moves)->ops = ops;
}

static void	first_moves(t_list **a, t_list **b, t_moves **moves)
{
	while (ft_lstsize((*a)) > 3)
		divide_a_by_median(a, b, moves, ft_lstsize((*a)));
	if (ft_lstsize((*a)) <= 3)
		sort_two_or_three(a, &(*moves)->ops);
}

static void	move_until_sorted(t_list **a, t_list **b, t_moves **moves)
{
	int	i;
	int	count;

	i = 0;
	while ((*moves)->chunks || !is_sorted(*a))
	{
		if ((*moves)->chunks->content <= 3)
		{
			while (i < (*moves)->chunks->content)
			{
				pa(a, b, &((*moves)->ops));
				i++;
			}
			i = 0;
			free_first_element(&(*moves)->chunks);
		}
		else
		{
			count = divide_b_by_median(b, a,
					&((*moves)->chunks), &((*moves)->ops));
			if (count > 3)
				divide_a_by_median(a, b, moves, count);
		}
		sort_top_three(a, &((*moves)->ops));
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_moves	*moves;

	a = parse_list(argc, argv);
	b = 0;
	moves = malloc(sizeof(t_moves));
	if (is_sorted(a))
		exit(EXIT_SUCCESS);
	init_struct(&moves);
	first_moves(&a, &b, &moves);
	move_until_sorted(&a, &b, &moves);
	print_operations(moves->ops);
	free_stack(&a);
	free_stack(&moves->ops);
	free_stack(&moves->chunks);
	free(moves);
}
