/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:41:09 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/01 12:41:10 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print(t_list *a, t_list *b, t_list *chunks)
{
	t_list* tmp;

	tmp = a;
	printf("PILE A: ");
	while (tmp) {
		printf("%d ", (tmp->content));
		tmp = tmp->next;
	}
	printf("\nPILE B: ");
	tmp = b;
	while (tmp) {
		printf("%d ", (tmp->content));
		tmp = tmp->next;
	}
	printf("\nCHUNKS: ");
	tmp = chunks;
	while (tmp) {
		printf("%d ", (tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
}

// int main() {
// 	t_list *a = 0;
// 	t_list *b = 0;
// 	int new5 = 5;
// 	int new4 = 4;
// 	int new3 = 3;
// 	int new2 = 2;
// 	int new1 = 1;
// 	int new = 0;

// 	ft_lstadd_back(&a, ft_lstnew(&new5));
// 	ft_lstadd_back(&a, ft_lstnew(&new4));
// 	ft_lstadd_back(&a, ft_lstnew(&new3));
// 	ft_lstadd_back(&a, ft_lstnew(&new2));
// 	ft_lstadd_back(&a, ft_lstnew(&new1));
// 	ft_lstadd_back(&a, ft_lstnew(&new));

// 	ft_print(a, b);
// 	pb(&a, &b);
// 	pb(&a, &b);
// 	pb(&a, &b);
// 	ft_print(a, b);
// 	sb(&b);
// 	ft_print(a, b);
// 	rb(&b);
// 	ft_print(a, b);
// 	rrb(&b);
// 	ft_print(a, b);
// 	ss(&a, &b);
// 	ft_print(a, b);
// 	pa(&a, &b);
// 	ft_print(a, b);
// 	sa(&a);
// 	ft_print(a, b);
// 	ra(&a);
// 	ft_print(a, b);
// 	rra(&a);
// 	ft_print(a, b);
// 	return (0);

// }
