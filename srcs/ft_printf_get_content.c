/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:02:22 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/11 16:04:35 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_get_content2(t_value_printf *value_printf, va_list *arg)
{
	if (value_printf->specifier == 's')
		return (ft_strdup(va_arg(*arg, char *)));
	if (value_printf->specifier == 'u')
		return (ft_itoa(va_arg(*arg, unsigned int)));
	if (value_printf->specifier == 'x')
		return (NULL);
	if (value_printf->specifier == 'X')
		return (NULL);
	if (value_printf->specifier == 'p')
		return (NULL);
	if (value_printf->specifier == 'n')
		return (ft_strdup(""));
	if (value_printf->specifier == '%')
		return (ft_strdup("%"));
	return (NULL);
}

char	*ft_get_content(t_value_printf *value_printf, va_list *arg)
{
	if (value_printf->specifier == 'c')
		return (ft_straddcharendstr("", va_arg(*arg, int)));
	if (value_printf->specifier == 'd')
		return (ft_itoa(va_arg(*arg, int)));
	if (value_printf->specifier == 'i')
		return (ft_itoa(va_arg(*arg, int)));
	if (value_printf->specifier == 'e')
		return (NULL);
	if (value_printf->specifier == 'E')
		return (NULL);
	if (value_printf->specifier == 'f')
		return (NULL);
	if (value_printf->specifier == 'g')
		return (NULL);
	if (value_printf->specifier == 'G')
		return (NULL);
	return (ft_get_content2(value_printf, arg));
}
