/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:40:35 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:40:36 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issymbol(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (n + 2));
	while (i <= n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	send_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

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

int *put_list_in_tab(t_list *stack, int size)
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
