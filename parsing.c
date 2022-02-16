#include "push_swap.h"

int	count_arguments(char *quoted_arg)
{
	int		i;
	char	*spaces;
	int		count;

	spaces = " \t\n\v\f\r";
	i = 0;
	quoted_arg = ft_strtrim(quoted_arg, spaces);
	while (quoted_arg[i])
	{
		if (ft_isdigit(quoted_arg[i]) && ft_isspace(quoted_arg[i + 1]))
			count++;
		else if (ft_isdigit(quoted_arg[i]) && i == ft_strlen(quoted_arg))
			count++;
		i++;
	}
	return (count);
}

void	parse_quotes(int argc, char **argv)
{
	int		nbr_of_args;
	char	**args_tab;
	int		i;

	nbr_of_args = count_arguments(argv[1]);
	if (nbr_of_args == 1)
		// fct Error
	// créer liste chainée avec un nb d'éléments qui correspond à nbr_of_args
	args_tab = ft_split(argv[1], ' ');
	while (args_tab[i])
	{
		// element de la liste = ft_atoi(args_tab[i]);
		i++;
	}
}

void	parse_list(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) <= 2) // si un seul arg dans guillemets
		// fct erreur
	else if (argc == 2 && ft_strlen(argv[1]) > 2) // si args envoyés dans guillemets
	{
		parse_quotes(argc, argv);
		
	}
}

