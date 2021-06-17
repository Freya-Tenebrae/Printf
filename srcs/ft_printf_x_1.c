/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:08:32 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/17 15:26:28 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_x_hh(t_value_printf *value_printf, unsigned char i, \
	int is_upper)
{
	int	l;

	l = ft_getlen_ull(i, 16);
	return (ft_printf_x_conditionning(value_printf, l, i, is_upper));
}

static int	ft_printf_x_h(t_value_printf *value_printf, unsigned short i, \
	int is_upper)
{
	int	l;

	l = ft_getlen_ull(i, 16);
	return (ft_printf_x_conditionning(value_printf, l, i, is_upper));
}

static int	ft_printf_x_l(t_value_printf *value_printf, unsigned long i, \
	int is_upper)
{
	int	l;

	l = ft_getlen_ull(i, 16);
	return (ft_printf_x_conditionning(value_printf, l, i, is_upper));
}

static int	ft_printf_x_ll(t_value_printf *value_printf, unsigned long long i, \
	int is_upper)
{
	int	l;

	l = ft_getlen_ull(i, 16);
	return (ft_printf_x_conditionning(value_printf, l, i, is_upper));
}

int	ft_printf_x(t_value_printf *value_printf, va_list *arg, int is_upper)
{
	unsigned int	i;
	int				l;

	if (ft_strcmp(value_printf->length, "hh") == 0)
		return (ft_printf_x_hh(value_printf, \
			(unsigned char)va_arg(*arg, unsigned int), is_upper));
	else if (ft_strcmp(value_printf->length, "h") == 0)
		return (ft_printf_x_h(value_printf, \
			(unsigned short)va_arg(*arg, unsigned int), is_upper));
	else if (ft_strcmp(value_printf->length, "l") == 0)
		return (ft_printf_x_l(value_printf, va_arg(*arg, unsigned long), \
			is_upper));
	else if (ft_strcmp(value_printf->length, "ll") == 0)
		return (ft_printf_x_ll(value_printf, va_arg(*arg, unsigned long long), \
			is_upper));
	i = va_arg(*arg, unsigned int);
	l = ft_getlen_ull(i, 16);
	return (ft_printf_x_conditionning(value_printf, l, i, is_upper));
}
