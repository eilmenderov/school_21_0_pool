SRCSDIR = srcs
INCLDIR = includes


SRCS = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

OBJS = ${addprefix ${SRCSDIR}/,${SRCS:.c=.o}}

NAME = libft.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:	
			${CC} ${CFLAGC} -I ${INCLDIR} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

-include $(OBJS:.o=.d)

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all