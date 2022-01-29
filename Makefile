FILES = newparsing.c ps_utils.c 

OBJS = ${FILES:.c=.o}

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

%.o:	%.c
	gcc -c ${FLAGS} -o $@ $<  

all:	${NAME}

${NAME}:${OBJS}
	${MAKE} -C ./LIBFT
	cp ./LIBFT/libft.a ${NAME}
	gcc ${FLAGS} -o ${NAME} ${OBJS} LIBFT/libft.a

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
