#include "push_swap.h"

void	update_chunks_list(t_list **chunks, int count)
{
	t_list	*tmp;

	tmp = (*chunks);
	if (count == 0)
	{
		(*chunks) = (*chunks)->next;
		free(tmp);
	}
	else
		(*chunks)->content = count;
}

void	init_stack_info(t_list *stack, t_info **info, int size)
{
	(*info) = malloc(sizeof(t_info));
	(*info)->stack_size = size;
	(*info)->median = get_median(stack, size);
	// (*info)->tridian = get_tridian(stack, 1, size);
	// (*info)->second_tridian = get_tridian(stack, 2, size) + 1;
	(*info)->tab = list_to_sorted_tab(stack, size);
}

void	divide_a_by_median(t_list **a, t_list **b, t_list **chunks, int size)
{
	t_info	*info;
	int		i;
	int		count;

	init_stack_info((*a), &info, size);
	i = 0;
	count = 0;
	while (i < info->stack_size)
	{
		if ((*a)->content > info->median)
			ra(a);
		else
		{
			pb(a, b);
			count++;
		}
		i++;
	}
	free(info);
	ft_lstadd_front(chunks, ft_lstnew(count));
}

int	divide_b_by_median(t_list **b, t_list **a, t_list **chunks)
{
	t_info	*info;
	int		i;
	int		count = 0;
	int		ret = (*chunks)->content;

	init_stack_info((*b), &info, (*chunks)->content);
	i = 0;
	// printf("chunk size = %d\n", (*chunks)->content);
	while  (i < info->stack_size)
	{
		if ((*b)->content > info->median)
			pa(a, b);
		else
		{
			rb(b);
			count++;
		}
		i++;
	}
	i = 0;
	while (i < count)
	{
		rrb(b);
		i++;
	}
	free(info);
	update_chunks_list(chunks, count);
	return (ret - count);
}

// void	divide_by_tridian(t_list **a, t_list **b, int size)
// {
// 	t_info	*info;
// 	int	i;

// 	init_stack_info((*a), &info, size);
// 	i = 0;
// 	printf("tridian = %d\n", info->tridian);
// 	printf("second tridian = %d\n", info->second_tridian);
// 	while (i < info->stack_size)
// 	{
// 		if ((*a)->content > info->second_tridian) // exemple : 67-100
// 			ra(a);
// 		else // exemple : 1-66
// 		{
// 			pb(a, b);
// 			if ((*b)->content <= info->tridian) // exemple : 1-33
// 				rb(b);
// 		}
// 		i++;
// 	}
// }

int	get_median(t_list *stack, int size)
{
	int	rank;
	int	*tab;

	tab = list_to_sorted_tab(stack, size);
	rank = (size / 2);
	return (tab[rank - 1]);
}

// int	get_tridian(t_list *stack, int index, int size)
// {
// 	int	rank;
// 	int	*tab;

// 	tab = list_to_sorted_tab(stack, size);
// 	rank = (size / 3) * index;
// 	return (tab[rank - 1]);
// }

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b = 0;
	t_list	*chunks = 0;
	int		count;
	int		i;
	
	a = parse_list(argc, argv);
	i = 0;
	while (ft_lstsize(a) > 3)
		divide_a_by_median(&a, &b, &chunks, ft_lstsize(a));
	if (ft_lstsize(a) <= 3)
		sort_two_or_three(&a);
	while (chunks || !is_sorted(a))
	{
		if (chunks->content <= 3)
		{
			while (i < chunks->content)
			{
				pa(&a, &b);
				i++;
			}
			i = 0;
			chunks = chunks->next;
		}
		else
		{
			count = divide_b_by_median(&b, &a, &chunks);
			if (count > 3)
				divide_a_by_median(&a, &b, &chunks, count);
		}
		sort_top_three(&a);
		// ft_print(a, b, chunks);
	}
}
