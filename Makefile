FILES = free.c main.c math.c operations.c operations2.c ps_parsing.c ps_utils.c ps_utils2.c sort_only3.c sort_top3.c print_ops.c sort_big_stack.c

OBJS = ${FILES:.c=.o}

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g

%.o:	%.c
	gcc -c ${FLAGS} -o $@ $<  

all:	${NAME}

${NAME}:${OBJS}
	${MAKE} -C ./LIBFT bonus
	# ${bonus} -C ./LIBFT
	cp ./LIBFT/libft.a ${NAME}
	gcc ${FLAGS} -o ${NAME} ${OBJS} LIBFT/libft.a

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
