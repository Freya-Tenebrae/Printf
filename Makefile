# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/06/15 15:39:15 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=$(addprefix ${FOLDER}/, \
	ft_printf.c \
	ft_printf_util.c \
	ft_printf_util_itoa.c \
	ft_printf_pars.c \
	ft_printf_get_content.c \
	ft_printf_c.c \
	ft_printf_s.c \
	ft_printf_i.c \
	ft_printf_u.c \
	ft_printf_o.c \
	ft_printf_x.c \
	ft_printf_conditioning_value.c)
SRCS_BONUS=$(addprefix ${FOLDER_BONUS}/, ft_printf_bonus.c)
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

HEADER=includes
FOLDER=srcs
FOLDER_BONUS=srcs_bonus
LIBFT=libft

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	cp libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADER)

bonus: $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	cp libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT)

fclean: clean
	${RM} libftprintf.a
	make fclean -C $(LIBFT)

re: fclean all

rebonus: fclean bonus
