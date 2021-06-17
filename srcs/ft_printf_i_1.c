/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/17 16:10:00 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_i_hh(t_value_printf *value_printf, signed char i)
{
	int	l;

	l = ft_getlen_ll(i, 10);
	return (ft_printf_i_conditionning(value_printf, l, i));
}

static int	ft_printf_i_h(t_value_printf *value_printf, short i)
{
	int	l;

	l = ft_getlen_ll(i, 10);
	return (ft_printf_i_conditionning(value_printf, l, i));
}

static int	ft_printf_i_l(t_value_printf *value_printf, long i)
{
	int	l;

	l = ft_getlen_ll(i, 10);
	return (ft_printf_i_conditionning(value_printf, l, i));
}

static int	ft_printf_i_ll(t_value_printf *value_printf, long long i)
{
	int	l;

	l = ft_getlen_ll(i, 10);
	return (ft_printf_i_conditionning(value_printf, l, i));
}

int	ft_printf_i(t_value_printf *value_printf, va_list *arg)
{
	int	i;
	int	l;

	if (ft_strcmp(value_printf->length, "hh") == 0)
		return (ft_printf_i_hh(value_printf, (signed char)va_arg(*arg, int)));
	else if (ft_strcmp(value_printf->length, "h") == 0)
		return (ft_printf_i_h(value_printf, (short)va_arg(*arg, int)));
	else if (ft_strcmp(value_printf->length, "l") == 0)
		return (ft_printf_i_l(value_printf, va_arg(*arg, long)));
	else if (ft_strcmp(value_printf->length, "ll") == 0)
		return (ft_printf_i_ll(value_printf, va_arg(*arg, long long)));
	i = va_arg(*arg, int);
	l = ft_getlen_ll(i, 10);
	return (ft_printf_i_conditionning(value_printf, l, i));
}
