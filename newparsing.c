#include "push_swap.h"
#include <stdio.h>

int	count_args(char **argv)
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
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]))
				send_error();
			if (ft_isdigit(argv[i][j]) && ft_isspace(argv[i][j + 1]))
				count++;
			else if (ft_isdigit(argv[i][j]) && !argv[i][j + 1])
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

int	parse_list(int argc, char **argv)
{
	if (argc < 2 || count_args(argv) <= 1)
		send_error();
	
}

int	main(int argc, char **argv)
{
	printf("%d\n", parse_list(argc, argv));
}
