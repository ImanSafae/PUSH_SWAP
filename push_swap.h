/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:19:23 by itaouil           #+#    #+#             */
/*   Updated: 2022/03/08 23:19:25 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "LIBFT/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

# define SA 1
# define SB 2
# define RA 3
# define RB 4
# define RRA 5
# define RRB 6
# define PA 7
# define PB 8

typedef struct s_info
{
	int	stack_size;
	int	median;
	int	*tab;
}			t_info;

typedef struct s_moves
{
	struct s_list	*chunks;
	struct s_list	*ops;
}				t_moves;

// PARSING
void	free_tab(char ***tab);
int		ft_isspace(char c);
int		ft_isdigit(int c);
char	*ft_strndup(char *str, int n);
int		issymbol(char c);
t_list	*parse_list(int argc, char **argv);
void	send_error(void);
int		is_sorted(t_list *stack);

// OPERATIONS
void	sa(t_list **stack_a, t_list **ops);
void	sb(t_list **stack_b, t_list **ops);
void	ra(t_list **stack_a, t_list **ops);
void	rb(t_list **stack_b, t_list **ops);
void	rra(t_list **stack_a, t_list **ops);
void	rrb(t_list **stack_b, t_list **ops);
void	pa(t_list **stack_a, t_list **stack_b, t_list **ops);
void	pb(t_list **stack_a, t_list **stack_b, t_list **ops);

// PRINT OPERATIONS
void	print_operations(t_list *ops);
void	print_last_op(t_list *ops);
void	check_rr(t_list **ops);
void	check_rrr(t_list **ops);
void	check_ss(t_list **ops);
void	check_useless_ops(t_list **ops);

// TEST
void	ft_print(t_list *a, t_list *b, t_list *chunks);

// SORT
void	sort_two_or_three(t_list **stack, t_list **ops);
void	sort_top_three(t_list **stack, t_list **ops);
// void	divide_by_tridian(t_list **a, t_list **b, int size);
void	divide_a_by_median(t_list **a, t_list **b, t_moves **moves, int size);
int		divide_b_by_median(t_list **b, t_list **a,
			t_list **chunks, t_list **ops);

// UTILS
void	sort_tab(int **tab, int limit);
int		*put_list_in_tab(t_list *stack, int size);
int		*list_to_sorted_tab(t_list *stack, int size);
// int		get_tridian(t_list *stack, int index, int size);
int		get_median(t_list *stack, int size);

#endif
