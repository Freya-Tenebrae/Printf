/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:02:22 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/25 08:25:46 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_content2(t_value_printf *value_printf, va_list *arg)
{
	if (value_printf->specifier == 'n')
		return (-1);
	if (value_printf->specifier == 'o')
		return (ft_printf_specifier_o(value_printf, arg));
	if (value_printf->specifier == 'f')
		return (ft_printf_specifier_f(value_printf, arg));
	if (value_printf->specifier == 'e')
		return (ft_printf_specifier_e(value_printf, arg, 0));
	if (value_printf->specifier == 'E')
		return (ft_printf_specifier_e(value_printf, arg, 1));
	if (value_printf->specifier == 'g')
		return (ft_printf_specifier_g(value_printf, arg, 0));
	if (value_printf->specifier == 'G')
		return (ft_printf_specifier_g(value_printf, arg, 1));
	return (-1);
}

int	ft_get_content(t_value_printf *value_printf, va_list *arg)
{
	if (value_printf->specifier == 'c')
		return (ft_printf_specifier_c(value_printf, arg));
	if (value_printf->specifier == '%')
		return (ft_printf_specifier_c(value_printf, NULL));
	if (value_printf->specifier == 's')
		return (ft_printf_specifier_s(value_printf, arg));
	if (value_printf->specifier == 'i' || value_printf->specifier == 'd')
		return (ft_printf_specifier_i(value_printf, arg));
	if (value_printf->specifier == 'u')
		return (ft_printf_specifier_u(value_printf, arg));
	if (value_printf->specifier == 'x')
		return (ft_printf_specifier_x(value_printf, arg, 0));
	if (value_printf->specifier == 'X')
		return (ft_printf_specifier_x(value_printf, arg, 1));
	if (value_printf->specifier == 'p')
		return (ft_printf_specifier_p(value_printf, arg));
	return (ft_get_content2(value_printf, arg));
}
