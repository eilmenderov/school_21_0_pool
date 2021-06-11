SRCS = rush02_par1.c rush02_par2.c rush02_main.c

OBJS = ${SRCS:.c=.o}

NAME = rush-02

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -o ${NAME}

.c.o:	
			${CC} ${CFLAGC} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

.PHONY: all clean fclean re

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

