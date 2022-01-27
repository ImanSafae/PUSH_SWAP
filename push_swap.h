#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "PSLIBFT/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

int		check_args_int(int argc, char **argv);
int		check_doublons(int argc, char **argv);
t_list	*create_stack(int argc, char **argv);

#endif