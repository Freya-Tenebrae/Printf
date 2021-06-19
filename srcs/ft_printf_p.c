/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:16:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/19 16:06:54 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_p_conditionning(t_value_printf *value_printf, int l, \
	unsigned long long p)
{
	char	*pre_value;
	char	*post_value;

	pre_value = ft_strdup("0x");
	post_value = ft_strdup("");
	l += 2;
	if (p == 0 && value_printf->precision == 0 && \
		value_printf->is_precision == 1)
		l--;
	l = ft_printf_conditionning_width(value_printf, l, &pre_value, &post_value);
	ft_putstr(pre_value);
	if (p != 0 || value_printf->precision != 0 || \
		value_printf->is_precision != 1)
		ft_putnbr_hex(p, 0);
	ft_putstr(post_value);
	free(pre_value);
	free(post_value);
	return (l);
}

int	ft_printf_p(t_value_printf *value_printf, va_list *arg)
{
	unsigned long long	p;
	int					l;

	p = va_arg(*arg, unsigned long long);
	l = ft_getlen_ull(p, 16);
	return (ft_printf_p_conditionning(value_printf, l, p));
}
