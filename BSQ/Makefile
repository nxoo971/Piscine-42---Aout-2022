SRCS = srcs/affichage.c srcs/algo.c srcs/check.c srcs/check2.c srcs/free.c srcs/free2.c srcs/main.c srcs/point_n_square.c srcs/t_info.c srcs/utils.c srcs/utils2.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = bsq
GCC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

.c.o:
	${GCC} ${FlAGS} -I ${INCS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${GCC} ${FLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
