/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:31:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/11 13:08:35 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include "../libft/libft.h"
# include <stdarg.h>
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_value_printf
{
	char					*flags;
	int						width;
	int						precision;
	char					*length;
	char					specifier;
	char					*content;
}							t_value_printf;
/* %[flags][width][.precision][length]specifier */
/* ************************************************************************** */
/*                                 FIRST PART                                 */
/* ************************************************************************** */
int							ft_printf(const char *input, ...);
int							ft_parsing(char *str, int i,
								t_value_printf *value_printf, va_list *arg);
char						*ft_get_content(t_value_printf *value_printf, \
								va_list *arg);
char						*ft_get_value(t_value_printf *value_printf);
int							ft_freeprintf(char **result, char **str);
int							ft_init_value_lst(t_value_printf *value_printf);
char						*ft_straddcharendstr(const char *s, char const c);
/* ************************************************************************** */
/*                                 BONUS PART                                 */
/* ************************************************************************** */

#endif
