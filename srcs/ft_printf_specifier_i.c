/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_i.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/25 08:24:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_i_conditionning_2(t_value_printf *value_printf, \
	long long *i, char ***value)
{
	int	tmpl;
	int	l;

	l = ft_getlen_ll(*i, 10);
	l = ft_printf_conditionning_precision(value_printf, l, &(*value)[0]);
	if (l < 0)
		return (l);
	tmpl = ft_printf_conditionning_sign(value_printf, i, &(*value)[0]);
	if (tmpl < 0)
		return (tmpl);
	l += tmpl;
	if (value_printf->is_precision == 1 && value_printf->precision == 0 \
		&& *i == 0)
		l -= 1;
	l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	if (value_printf->is_precision != 1 || value_printf->precision != 0 \
		|| *i != 0)
		ft_putnbr_ull(*i);
	ft_putstr((*value)[1]);
	return (l);
}

static int	ft_printf_i_conditionning_1(t_value_printf *value_printf, \
	long long i)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_i_conditionning_2(value_printf, &i, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_specifier_i(t_value_printf *value_printf, va_list *arg)
{
	if (ft_strcmp(value_printf->length, "hh") == 0)
		return (ft_printf_i_conditionning_1(value_printf, \
			(signed char)va_arg(*arg, int)));
	else if (ft_strcmp(value_printf->length, "h") == 0)
		return (ft_printf_i_conditionning_1(value_printf, \
			(short)va_arg(*arg, int)));
	else if (ft_strcmp(value_printf->length, "l") == 0)
		return (ft_printf_i_conditionning_1(value_printf, \
			va_arg(*arg, long)));
	else if (ft_strcmp(value_printf->length, "ll") == 0)
		return (ft_printf_i_conditionning_1(value_printf, \
			va_arg(*arg, long long)));
	return (ft_printf_i_conditionning_1(value_printf, va_arg(*arg, int)));
}
