#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_args_int(int argc, char **argv)
{
	int		i;
	int		j;
	char	*spaces;

	i = argc - 1;
	j = 0;
	spaces = " +\t\n\v\f\r";
	while (i >= 1)
	{
		argv[i] = ft_strtrim(argv[i], spaces);
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i--;
	}
	return (1);
}

int	check_doublons(int argc, char **argv)
{
	int		i;
	int		j;
	char	*spaces;

	i = 1;
	j = i + 1;
	spaces = " +\t\n\v\f\r";
	while (argv[i])
	{
		while (argv[j])
		{
			if (!ft_strcmp(ft_strtrim(argv[i], spaces), ft_strtrim(argv[j], spaces)))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

t_list	*create_stack(int argc, char **argv)
{
	t_list	*stack;
	t_list	*pointer;
	int		i;
	int		*content;

	content = malloc(sizeof(int));
	*content = ft_atoi(argv[1]);
	stack = ft_lstnew(content);
	pointer = stack;
	i = 2;
	while (i < argc)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(argv[i]);
		pointer = ft_lstnew(content);
		ft_lstadd_back(&stack, pointer);
		i++;
	}
	return (stack);
}
