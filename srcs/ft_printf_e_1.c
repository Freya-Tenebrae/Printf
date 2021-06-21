/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:30:28 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/21 19:31:03 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_e(t_value_printf *value_printf, va_list *arg, int is_upper)
{
	double	f;

	f = va_arg(*arg, double);
	return (ft_printf_e_conditionning_1(value_printf, 0, f, is_upper));
}
