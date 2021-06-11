SRCS = main.c

OBJS = ${SRCS:.c=.o}

NAME = ft_cat

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
