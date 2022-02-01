#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "LIBFT/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

// int		check_args_int(int argc, char **argv);
// int		check_doublons(int argc, char **argv);
// t_list	*create_stack(int argc, char **argv);
void		free_tab(char ***tab);
int			ft_isspace(char c);
int			ft_isdigit(int c);
char		*ft_strndup(char *str, int n);
int			issymbol(char c);
void		parse_list(int argc, char **argv);
void		send_error(void);

#endif