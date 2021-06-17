/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:08:52 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/17 16:10:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_u_hh(t_value_printf *value_printf, unsigned char i)
{
	int	l;

	l = ft_getlen_ull(i, 10);
	return (ft_printf_u_conditionning(value_printf, l, i));
}

static int	ft_printf_u_h(t_value_printf *value_printf, unsigned short i)
{
	int	l;

	l = ft_getlen_ull(i, 10);
	return (ft_printf_u_conditionning(value_printf, l, i));
}

static int	ft_printf_u_l(t_value_printf *value_printf, unsigned long i)
{
	int	l;

	l = ft_getlen_ull(i, 10);
	return (ft_printf_u_conditionning(value_printf, l, i));
}

static int	ft_printf_u_ll(t_value_printf *value_printf, unsigned long long i)
{
	int	l;

	l = ft_getlen_ull(i, 10);
	return (ft_printf_u_conditionning(value_printf, l, i));
}

int	ft_printf_u(t_value_printf *value_printf, va_list *arg)
{
	unsigned int	i;
	int				l;

	if (ft_strcmp(value_printf->length, "hh") == 0)
		return (ft_printf_u_hh(value_printf, \
			(unsigned char)va_arg(*arg, unsigned int)));
	else if (ft_strcmp(value_printf->length, "h") == 0)
		return (ft_printf_u_h(value_printf, \
			(unsigned short)va_arg(*arg, unsigned int)));
	else if (ft_strcmp(value_printf->length, "l") == 0)
		return (ft_printf_u_l(value_printf, va_arg(*arg, unsigned long)));
	else if (ft_strcmp(value_printf->length, "ll") == 0)
		return (ft_printf_u_ll(value_printf, va_arg(*arg, unsigned long long)));
	i = va_arg(*arg, unsigned int);
	l = ft_getlen_ull(i, 10);
	return (ft_printf_u_conditionning(value_printf, l, i));
}
