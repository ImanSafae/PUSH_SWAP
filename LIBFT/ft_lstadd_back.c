#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*pointer;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	pointer = *alst;
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
	}
	pointer->next = new;
}