#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pointer;

	pointer = lst;
	while (pointer != NULL)
	{
		f(pointer->content);
		pointer = pointer->next;
	}
}
