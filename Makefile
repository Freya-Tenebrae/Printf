# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/06/06 14:21:52 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=$(addprefix ${FOLDER}/, ft_printf.c)
SRCS_BONUS=$(addprefix ${FOLDER}/, )
OBJS=$(SRC:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

HEADER=includes
FOLDER=srcs
LIBFT=libft

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADER)

bonus: $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT)

fclean: clean
	${RM} libftprintf.a
	make fclean -C $(LIBFT)

re: fclean all

rebonus: fclean bonus
