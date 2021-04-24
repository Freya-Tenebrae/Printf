# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/04/24 19:36:14 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCs=$(addprefix ${FOLDER}/, ft_printf.c)
OBJS=${SRC:.c=.o}

HEADER=includes
FOLDER=srcs
LIBFT=libft

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cp libft/libft.a ./${NAME}
	ar -rcs ${NAME} ${OBJS}

bonus: ${NAME}

%.o: %.c
	${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

clean:
	${RM} ${OBJS}
	make clean -C $(LIBFT)

fclean: clean
	${RM} libftprintf.a
	make fclean -C $(LIBFT)

re: fclean all
	
