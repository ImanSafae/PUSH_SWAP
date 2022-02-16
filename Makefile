FILES = newparsing.c ps_utils.c sort_only3.c sort_top3.c operations.c test.c

OBJS = ${FILES:.c=.o}

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g

%.o:	%.c
	gcc -c ${FLAGS} -o $@ $<  

all:	${NAME}

${NAME}:${OBJS}
	${MAKE} -C ./LIBFT
	${BONUS} -C ./LIBFT
	cp ./LIBFT/libft.a ${NAME}
	gcc ${FLAGS} -o ${NAME} ${OBJS} LIBFT/libft.a

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
