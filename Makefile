# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/06/22 18:07:07 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=$(addprefix ${FOLDER}/, \
	ft_printf.c \
	ft_printf_pars.c \
	ft_printf_get_content.c \
	ft_printf_conditioning.c \
	ft_printf_tools_1.c \
	ft_printf_tools_2.c \
	ft_printf_tools_3.c \
	ft_printf_tools_4.c \
	ft_printf_s.c \
	ft_printf_c_1.c \
	ft_printf_c_2.c \
	ft_printf_p.c \
	ft_printf_i_1.c \
	ft_printf_i_2.c \
	ft_printf_u_1.c \
	ft_printf_u_2.c \
	ft_printf_o_1.c \
	ft_printf_o_2.c \
	ft_printf_x_1.c \
	ft_printf_x_2.c \
	ft_printf_f_1.c \
	ft_printf_f_2.c \
	ft_printf_e_1.c \
	ft_printf_e_2.c)
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

bonus: $(OBJS)
	make -C $(LIBFT) bonus
	cp libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT)

fclean: clean
	${RM} libftprintf.a
	make fclean -C $(LIBFT)

re: fclean all

rebonus: fclean bonus
