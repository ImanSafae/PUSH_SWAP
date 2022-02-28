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

typedef struct s_info
{
	int	stack_size;
	int	median;
	// int	tridian;
	// int	second_tridian;
	int	*tab;
}			t_info;

// int		check_args_int(int argc, char **argv);
// int		check_doublons(int argc, char **argv);
// t_list	*create_stack(int argc, char **argv);

// PARSING
void		free_tab(char ***tab);
int			ft_isspace(char c);
int			ft_isdigit(int c);
char		*ft_strndup(char *str, int n);
int			issymbol(char c);
t_list		*parse_list(int argc, char **argv);
void		send_error(void);
int			is_sorted(t_list *stack);

// OPERATIONS
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
// void	print_operations(t_list *ops);

// TEST
void	ft_print(t_list *a, t_list *b, t_list *chunks);

// SORT
void	sort_two_or_three(t_list **stack);
void	sort_top_three(t_list **stack);
// void	divide_by_tridian(t_list **a, t_list **b, int size);
void	divide_a_by_median(t_list **a, t_list **b, t_list **chunks, int size);

// UTILS
void	sort_tab(int **tab, int limit);
int		*put_list_in_tab(t_list *stack, int size);
int		*list_to_sorted_tab(t_list *stack, int size);
// int		get_tridian(t_list *stack, int index, int size);
int		get_median(t_list *stack, int size);

#endif