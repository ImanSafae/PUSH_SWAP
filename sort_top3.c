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
	if (top > middle)
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
	if (middle > top && middle > bottom)
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
	if (top < middle && middle < bottom)
		rra(stack);
}

void	sort_top_three(t_list **stack)
{
	while (!is_sorted(*stack))
	{
		check_ra(stack);
		check_sa(stack);
		check_rra(stack);
	}
}
