# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/04/24 00:34:04 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRC=ft_printf.c
OBJS=${SRC:.c=.o}

HEADER=includes
FOLDER=srcs

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} libftprintf.a

re: fclean all
