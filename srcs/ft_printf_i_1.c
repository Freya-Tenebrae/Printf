/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/23 13:02:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_i(t_value_printf *value_printf, va_list *arg)
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
