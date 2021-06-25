# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/06/25 08:27:22 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=$(addprefix ${FOLDER}/, \
	ft_printf.c \
	ft_printf_get_content.c \
	ft_printf_pars.c \
	ft_printf_specifier_c.c \
	ft_printf_specifier_e.c \
	ft_printf_specifier_f.c \
	ft_printf_specifier_g.c \
	ft_printf_specifier_i.c \
	ft_printf_specifier_o.c \
	ft_printf_specifier_p.c \
	ft_printf_specifier_s.c \
	ft_printf_specifier_u.c \
	ft_printf_specifier_x.c \
	ft_printf_tools_conditioning_1.c \
	ft_printf_tools_conditioning_2.c \
	ft_printf_tools_ftoa.c \
	ft_printf_tools_lenght.c \
	ft_printf_tools_other.c \
	ft_printf_tools_printing.c \
	ft_printf_tools_utility.c)
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
