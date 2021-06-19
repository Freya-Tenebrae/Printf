/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:31:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/18 11:05:41 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <float.h>
# include "../libft/libft.h"
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_value_printf
{
	char	*flags;
	int		width;
	int		is_precision;
	int		precision;
	char	*length;
	char	specifier;
}			t_value_printf;
/* %[flags][width][.precision][length]specifier */
/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int			ft_printf(const char *input, ...);
int			ft_parsing(char *str, int *i, t_value_printf *value_printf, \
				va_list *arg);
int			ft_get_content(t_value_printf *value_printf, va_list *arg);
/* ************************************************************************** */
/*                                 SPECIFIER                                  */
/* ************************************************************************** */
/* *********************************** c ************************************ */
int			ft_printf_c(t_value_printf *value_printf, va_list *arg);
/* *********************************** s ************************************ */
int			ft_printf_s(t_value_printf *value_printf, va_list *arg);
/* *********************************** i ************************************ */
int			ft_printf_i(t_value_printf *value_printf, va_list *arg);
int			ft_printf_i_conditionning(t_value_printf *value_printf, int l, \
				long long i);
/* *********************************** u ************************************ */
int			ft_printf_u(t_value_printf *value_printf, va_list *arg);
int			ft_printf_u_conditionning(t_value_printf *value_printf, int l, \
				unsigned long long i);
/* *********************************** o ************************************ */
int			ft_printf_o(t_value_printf *value_printf, va_list *arg);
int			ft_printf_o_conditionning(t_value_printf *value_printf, int l, \
				unsigned long long i);
/* *********************************** x ************************************ */
int			ft_printf_x(t_value_printf *value_printf, va_list *arg, \
				int is_upper);
int			ft_printf_x_conditionning(t_value_printf *value_printf, int l, \
				unsigned long long i, int is_upper);
/* *********************************** p ************************************ */
int			ft_printf_p(t_value_printf *value_printf, va_list *arg);
/* *********************************** n ************************************ */
/* *********************************** f ************************************ */
int			ft_printf_f(t_value_printf *value_printf, va_list *arg);
/* *********************************** e ************************************ */
/* *********************************** g ************************************ */
/* ************************************************************************** */
/*                             CONDITIONNING TOOL                             */
/* ************************************************************************** */
int			ft_printf_conditionning_precision(t_value_printf *value_printf, \
				int l, char **pre_value);
int			ft_printf_conditionning_sign(t_value_printf *value_printf, \
				long long *i, char **pre_value);
int			ft_printf_conditionning_width(t_value_printf *value_printf, int l, \
				char **pre_value, char **post_value);
/* ************************************************************************** */
/*                               PRINTING TOOL                                */
/* ************************************************************************** */
void		ft_putnbr_oct(unsigned long long n);
void		ft_putnbr_ull(unsigned long long n);
void		ft_putnbr_hex(unsigned long long n, int is_upper);
void		ft_putwchar(wint_t c);
void		ft_putwstr(wchar_t *s);
/* ************************************************************************** */
/*                                 OTHER TOOL                                 */
/* ************************************************************************** */
int			ft_getlen_ull(unsigned long long n, int i);
int			ft_getlen_ll(long long n, int i);
char		*ft_nftoa(double f, int precision);
int			ft_init_value_lst(t_value_printf *value_printf);
char		*ft_straddcharendstr(const char *s, char const c);
char		*ft_straddcharstartstr(const char *s, char const c);
/* ************************************************************************** */
/*                                 BONUS PART                                 */
/* ************************************************************************** */

#endif
