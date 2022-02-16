#include "push_swap.h"

static void	check_sa(t_list **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (int)((*stack)->content);
	middle = (int)((*stack)->next->content);
	bottom = (int)((*stack)->next->next->content);
	if (is_sorted((*stack)))
		return ;
	if (top < bottom && bottom < middle)
		sa(stack);
	else if (bottom < middle && middle < top)
		sa (stack);
	else if (middle < top && top < bottom)
		sa(stack);
}

static void	check_ra(t_list **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (int)((*stack)->content);
	middle = (int)((*stack)->next->content);
	bottom = (int)((*stack)->next->next->content);
	if (is_sorted((*stack)))
		return ;
	if (middle < bottom && bottom < top)
		ra(stack);
}

static void	check_rra(t_list **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (int)((*stack)->content);
	middle = (int)((*stack)->next->content);
	bottom = (int)((*stack)->next->next->content);
	if (is_sorted((*stack)))
		return ;
	if (bottom < top && top < middle)
		rra(stack);
}

void	sort_two_or_three(t_list **stack)
{
	if (ft_lstsize((*stack)) == 2)
	{
		if (!is_sorted((*stack)))
			sa(stack);
		return ;
	}
	else if (ft_lstsize((*stack)) == 3)
	{
		while (!is_sorted((*stack)))
		{
			check_sa(stack);
			check_ra(stack);
			check_rra(stack);
		}
	}
}
