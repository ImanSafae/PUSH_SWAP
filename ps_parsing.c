/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:39:50 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:39:52 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	check_doublons(t_list *stack)
{
	t_list	*tmp;

	tmp = stack->next;
	while (stack->next)
	{
		while (tmp)
		{
			if (stack->content == tmp->content)
				send_error();
			tmp = tmp->next;
		}
		stack = stack->next;
		tmp = stack->next;
	}
}

static void	add_nbr_to_stack(t_list **stack, char *nbr, int index)
{
	long	number;

	(void)index;
	number = ft_atoi(nbr);
	if (number > INT_MAX || number < INT_MIN)
		send_error();
	if (index == 1)
		(*stack)->content = number;
	else
		ft_lstadd_back(stack, ft_lstnew(number));
}

static int	count_args(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j])
				&& !issymbol(argv[i][j]))
				send_error();
			if (issymbol(argv[i][j]) && !ft_isdigit(argv[i][j + 1]))
				send_error();
			if ((ft_isdigit(argv[i][j]) && ft_isspace(argv[i][j + 1]))
				|| (ft_isdigit(argv[i][j]) && !argv[i][j + 1]))
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

static t_list	*create_stack(char **argv)
{
	t_list	*stack_a;
	int		i;
	int		j;
	char	**tab;
	int		index;

	i = 1;
	j = 0;
	index = 0;
	stack_a = ft_calloc(1, sizeof(t_list));
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		while (tab[j])
		{
			index++;
			add_nbr_to_stack(&stack_a, tab[j], index);
			j++;
		}
		i++;
		free_tab(&tab);
		j = 0;
	}
	return (stack_a);
}

t_list	*parse_list(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2 || count_args(argv) < 1)
		exit(EXIT_FAILURE);
	stack_a = create_stack(argv);
	check_doublons(stack_a);
	return (stack_a);
}
