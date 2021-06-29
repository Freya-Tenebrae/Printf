/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_f.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:49:38 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/29 09:05:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_f_conditionning_2(t_value_printf *value_printf, \
	double *f, char ***value)
{
	int	l;
	int	tmpl;

	l = ft_printf_conditionning_precision_f(value_printf, *f, &(*value)[1]);
	if (l < 0)
		return (l);
	tmpl = ft_printf_conditionning_sign(value_printf, (long long *)f, \
		&(*value)[0]);
	if (tmpl < 0)
		return (tmpl);
	l += tmpl;
	l = ft_printf_conditionning_width_f(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	ft_putstr((*value)[1]);
	return (l);
}

int	ft_printf_f_conditionning_1(t_value_printf *value_printf, double f)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_f_conditionning_2(value_printf, &f, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_specifier_f(t_value_printf *value_printf, va_list *arg)
{
	return (ft_printf_f_conditionning_1(value_printf, va_arg(*arg, double)));
}
