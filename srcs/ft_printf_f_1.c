/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:49:38 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/21 17:06:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_f(t_value_printf *value_printf, va_list *arg)
{
	double	f;

	f = va_arg(*arg, double);
	return (ft_printf_f_conditionning_1(value_printf, 0, f));
}
