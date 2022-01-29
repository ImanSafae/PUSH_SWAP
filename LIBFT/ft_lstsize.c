#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;
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
