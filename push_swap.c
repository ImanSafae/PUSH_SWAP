#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*pointer;

	if (argc < 3 || !check_args_int(argc, argv) || !check_doublons(argc, argv))
	{
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	stacka = create_stack(argc, argv);
	pointer = stacka;
	// while(pointer->next)
	// {
	// 	printf("%d\n", *((int *)(pointer->content)));
	// 	pointer = pointer->next;
	// }
	// printf("%d\n", *((int *)(pointer->content)));
}
