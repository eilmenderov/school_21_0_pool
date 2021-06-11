SRCS = main.c ft_oper.c ft_integ.c

OBJS = ${SRCS:.c=.o}

NAME = do-op

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -o ${NAME}

.c.o:	
			${CC} ${CFLAGC} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
