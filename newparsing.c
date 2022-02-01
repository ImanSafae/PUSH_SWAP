#include "push_swap.h"
#include <stdio.h>

static t_list	*add_nbr_to_stack(t_list **first_element, char* nbr, int index)
{
	t_list	*new;
	int		number;

	number = ft_atoi(nbr);
	if (index == 1)
		(*first_element)->content = (void *)&number;
	else
	{
		new = ft_calloc(1, sizeof(t_list));
		new->content = (void *)&number;
		ft_lstadd_back(first_element, new);
	}
	return (*first_element);
}

static int	count_args(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (argv[i])
	{
		while(argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]) && !issymbol(argv[i][j]))
				send_error();
			if ((ft_isdigit(argv[i][j]) && ft_isspace(argv[i][j + 1]))
				|| (ft_isdigit(argv[i][j]) && !argv[i][j + 1]))
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

static t_list	*create_stack(char **argv)
{
	t_list	*stack_a;
	int		i;
	int		j;
	char	**tab;
	int		index;

	i = 1;
	j = 0;
	index = 0;
	stack_a = ft_calloc(1, sizeof(t_list));
	while (argv[i])
	{	tab = ft_split(argv[i], ' ');
		while (tab[j])
		{
			index++;
			// printf("%s\n", tab[j]);
			stack_a = add_nbr_to_stack(&stack_a, tab[j], index);
			j++;
		}
		i++;
		free_tab(&tab);
		j = 0;
	}
	return (stack_a);
}

// static t_list	*create_stack(char **argv)
// {
// 	t_list	*stack_a;
// 	int		i;
// 	int		j;
// 	int		index;
// 	char	*nbr;
// 	int		new_nbr;
// 	int		start;

// 	index = 0;
// 	i = 1;
// 	j = 0;
// 	new_nbr = 0;
// 	stack_a = ft_calloc(1, sizeof(t_list));
// 	while (argv[i])
// 	{
// 		while (argv[i][j])
// 		{
// 			if ((ft_isdigit(argv[i][j]) && j == 0) || (ft_isdigit(argv[i][j]) && !ft_isdigit(argv[i][j - 1])))
// 			{
// 				new_nbr = TRUE;
// 				start = j;
// 			}
// 			else
// 				new_nbr = FALSE;
// 			if ((ft_isdigit(argv[i][j]) && ft_isspace(argv[i][j + 1]))
// 				|| (ft_isdigit(argv[i][j]) && !argv[i][j + 1]))
// 			{
// 				index++;
// 				nbr = ft_substr(argv[i], start, (j - start + 1));
// 				printf("%s\n", nbr);
// 				stack_a = add_nbr_to_stack(&stack_a, nbr, index);
// 				free(nbr);
// 			}
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	return (stack_a);
// }

void	parse_list(int argc, char **argv)
{
	
	t_list	*stack_a;
	// t_list	*stack_b;

	// vérifier que des arguments sont bien envoyés et qu'il y a au moins un chiffre
	if (argc < 2 || count_args(argv) < 1)
		exit(EXIT_FAILURE);
	stack_a = create_stack(argv);
	printf("%d\n", count_args(argv));
	printf("%d\n", ft_lstsize(stack_a));
}

int	main(int argc, char **argv)
{
	parse_list(argc, argv);
}
