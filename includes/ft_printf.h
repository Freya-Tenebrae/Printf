/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:31:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/16 12:15:42 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <stdarg.h>
# include "../libft/libft.h"
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct	s_value_printf
{
	char		*flags;
	int			width;
	int			precision;
	char		*length;
	char		specifier;
}				t_value_printf;
/* %[flags][width][.precision][length]specifier */
/* ************************************************************************** */
/*                                 FIRST PART                                 */
/* ************************************************************************** */
int				ft_printf(const char *input, ...);
int				ft_parsing(char *str, int *i, t_value_printf *value_printf, \
					va_list *arg);
int				ft_get_content(t_value_printf *value_printf, va_list *arg);
int				ft_printf_c(t_value_printf *value_printf, char c);
int				ft_printf_s(t_value_printf *value_printf, char *s);
int				ft_printf_i(t_value_printf *value_printf, long long i);
int				ft_printf_u(t_value_printf *value_printf, unsigned long long i);
int				ft_printf_o(t_value_printf *value_printf, unsigned long long i);
int				ft_printf_x(t_value_printf *value_printf, \
					unsigned long long i, int maj);
char			*ft_get_value(t_value_printf *value_printf, char *content);



char	*ft_itoa_octale(unsigned long long n);
char	*ft_itoa_unsigned(unsigned long long n);
char	*ft_itoa_hexadecimal(unsigned long long n);


int				ft_init_value_lst(t_value_printf *value_printf);
char			*ft_straddcharendstr(const char *s, char const c);
/* ************************************************************************** */
/*                                 BONUS PART                                 */
/* ************************************************************************** */

#endif
