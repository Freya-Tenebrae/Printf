/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:02:22 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/15 12:46:03 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_content2(t_value_printf *value_printf, va_list *arg)
{
	(void)value_printf;
	(void)arg;
	if (value_printf->specifier == 'u')
		return (-1);
	if (value_printf->specifier == 'o')
		return (ft_printf_o(value_printf, va_arg(*arg, size_t)));
	if (value_printf->specifier == 'x')
		return (ft_printf_x(value_printf, va_arg(*arg, size_t), 0));
	if (value_printf->specifier == 'X')
		return (ft_printf_x(value_printf, va_arg(*arg, size_t), 1));
	if (value_printf->specifier == 'p')
		return (-1);
	if (value_printf->specifier == 'e')
		return (-1);
	if (value_printf->specifier == 'E')
		return (-1);
	if (value_printf->specifier == 'f')
		return (-1);
	if (value_printf->specifier == 'g')
		return (-1);
	if (value_printf->specifier == 'G')
		return (-1);
	if (value_printf->specifier == 'n')
		return (0);
	return (-1);
}

int	ft_get_content(t_value_printf *value_printf, va_list *arg)
{
	if (value_printf->specifier == 'c')
		return (ft_printf_c(value_printf, va_arg(*arg, int)));
	if (value_printf->specifier == '%')
		return (ft_printf_c(value_printf, '%'));
	if (value_printf->specifier == 's')
		return (ft_printf_s(value_printf, va_arg(*arg, char *)));
	if (value_printf->specifier == 'i')
		return (ft_printf_i(value_printf, va_arg(*arg, int)));
	if (value_printf->specifier == 'd')
		return (ft_printf_i(value_printf, va_arg(*arg, int)));
	return (ft_get_content2(value_printf, arg));
}
