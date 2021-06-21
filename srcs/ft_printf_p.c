/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:16:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/21 20:06:29 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_p_conditionning_2(t_value_printf *value_printf, \
	int l, unsigned long long p, char ***value)
{
	l += 2;
	if (p == 0 && value_printf->precision == 0 && \
		value_printf->is_precision == 1)
		l--;
	l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l >= 0)
	{
		ft_putstr((*value)[0]);
		if (p != 0 || value_printf->precision != 0 || \
			value_printf->is_precision != 1)
			ft_putnbr_hex(p, 0);
		ft_putstr((*value)[1]);
	}
	return (l);
}

static int	ft_printf_p_conditionning_1(t_value_printf *value_printf, int l, \
	unsigned long long p)
{
	char	**value;

	value = malloc(sizeof(char **) * 2);
	if (!value)
		return (-1);
	value[0] = ft_strdup("0x");
	if (!value[0])
	{
		free(value);
		return (-1);
	}
	value[1] = ft_strdup("");
	if (!value[1])
	{
		free(value[0]);
		free(value);
		return (-1);
	}
	l = ft_printf_p_conditionning_2(value_printf, l, p, &value);
	free(value[0]);
	free(value[1]);
	free(value);
	return (l);
}

int	ft_printf_p(t_value_printf *value_printf, va_list *arg)
{
	unsigned long long	p;
	int					l;

	p = va_arg(*arg, unsigned long long);
	l = ft_getlen_ull(p, 16);
	return (ft_printf_p_conditionning_1(value_printf, l, p));
}
