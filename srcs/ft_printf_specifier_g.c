/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_g.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 08:15:00 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/29 09:34:43 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_specifier_g(t_value_printf *value_printf, va_list *arg, \
	int is_upper)
{
	double value;

	value = va_arg(*arg, double);
	if (value_printf->precision == 0 && value_printf->is_precision == 0)
		value_printf->precision = 6;
	if ((value >= 0.0001 && value < ft_powerten(value_printf->precision)) || \
		(value <= -0.0001 && \
		value > ft_powerten(value_printf->precision) * -1) || \
		value == 0)
		return (ft_printf_f_conditionning_1(value_printf, value)); // sans print les 0
	return	(ft_printf_e_conditionning_1(value_printf, value, is_upper));
}
