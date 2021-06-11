# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vleida <vleida@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 13:11:04 by tlaureen          #+#    #+#              #
#    Updated: 2021/03/24 13:44:45 by vleida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS =	main.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_read_map_p1.c ft_read_map_p2.c \
		ft_solve_map.c ft_print_map.c ft_puterror.c
		
OBJECTS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJECTS}
	gcc ${FLAGS} -o ${NAME} ${OBJECTS}

obj: ${OBJECTS}	

%.o: %.c
	gcc ${CFLAGS} -c $< -o $@

clean:
	/bin/rm -f ${OBJECTS}

fclean:	clean
	/bin/rm -f ${NAME}

re: fclean all
