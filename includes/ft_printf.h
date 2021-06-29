/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:31:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/29 09:34:26 by cmaginot         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int			ft_printf(const char *input, ...);
int			ft_parsing(char **str, t_value_printf *value_printf, va_list *arg);
int			ft_get_content(t_value_printf *value_printf, va_list *arg);
/* ************************************************************************** */
/*                                 SPECIFIER                                  */
/* ************************************************************************** */
int			ft_printf_specifier_c(t_value_printf *value_printf, va_list *arg);
int			ft_printf_specifier_e(t_value_printf *value_printf, va_list *arg, \
				int is_upper);
int			ft_printf_e_conditionning_1(t_value_printf *value_printf, \
				double f, int is_upper);
int			ft_printf_specifier_f(t_value_printf *value_printf, va_list *arg);
int			ft_printf_f_conditionning_1(t_value_printf *value_printf, double f);
int			ft_printf_specifier_g(t_value_printf *value_printf, va_list *arg, \
				int is_upper);
int			ft_printf_specifier_i(t_value_printf *value_printf, va_list *arg);
/* *********************************** n ************************************ */
int			ft_printf_specifier_o(t_value_printf *value_printf, va_list *arg);
int			ft_printf_specifier_p(t_value_printf *value_printf, va_list *arg);
int			ft_printf_specifier_s(t_value_printf *value_printf, va_list *arg);
int			ft_printf_specifier_u(t_value_printf *value_printf, va_list *arg);
int			ft_printf_specifier_x(t_value_printf *value_printf, va_list *arg, \
				int is_upper);
/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
/* ****************************** Conditioning ****************************** */
int			ft_printf_conditionning_precision(t_value_printf *value_printf, \
				int l, char **pre_value);
int			ft_printf_conditionning_precision_s(t_value_printf *value_printf, \
				int l, char **pre_value, char *s);
int			ft_printf_conditionning_precision_ws(t_value_printf *value_printf, \
				int l, wchar_t **ws);
int			ft_printf_conditionning_precision_f(t_value_printf *value_printf, \
				double f, char **post_value);
int			ft_printf_conditionning_sign(t_value_printf *value_printf, \
				long long *i, char **pre_value);
int			ft_printf_conditionning_width(t_value_printf *value_printf, int l, \
				char **pre_value, char **post_value);
int			ft_printf_conditionning_width_f(t_value_printf *value_printf, \
				int l, char **pre_value, char **post_value);
/* ********************************** ftoa ********************************** */
char		*ft_nftoa(double f, int precision);
/* ********************************* Lenght ********************************* */
int			ft_getlen_ull(unsigned long long n, int i);
int			ft_getlen_ll(long long n, int i);
int			ft_wstrlen(const wchar_t *s);
/* ********************************* Other ********************************** */
char		*ft_itoa_power(int power_ten);
char		*ft_straddcharendstr(const char *s, char const c);
char		*ft_straddcharstartstr(const char *s, char const c);
wchar_t		*ft_wstrndup(const wchar_t *ws1, size_t n);
wchar_t		*ft_wstrdup(const wchar_t *ws1);
/* ******************************** Printing ******************************** */
void		ft_putnbr_oct(unsigned long long n);
void		ft_putnbr_ull(unsigned long long n);
void		ft_putnbr_hex(unsigned long long n, int is_upper);
void		ft_putwchar(wint_t c);
void		ft_putwstr(wchar_t *s);
/* ********************************* Utility ******************************** */
int			ft_init_value_lst(t_value_printf *value_printf);
int			ft_init_value_conditionning(char ***value);
void		ft_free_value_conditionning(char ***value);
int			ft_powerten(int i);

#endif
