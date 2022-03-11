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

// char	*ft_strndup(char *str, int n)
// {
// 	int		i;
// 	char	*res;

// 	i = 0;
// 	res = malloc(sizeof(char) * (n + 2));
// 	while (i <= n)
// 	{
// 		res[i] = str[i];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

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
