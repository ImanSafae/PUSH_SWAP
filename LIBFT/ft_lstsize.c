/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:25:24 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/08 23:25:26 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*counter;

	if (!lst)
		return (0);
	count = 1;
	counter = lst->next;
	while (counter != NULL)
	{
		count++;
		counter = counter->next;
	}
	return (count);
}
