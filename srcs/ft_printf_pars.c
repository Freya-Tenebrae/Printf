/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:17:59 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/09 17:25:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_get_content2(t_value_printf *value_printf, va_list *arg)
{
	if (value_printf->specifier == 's')
		return (va_arg(*arg, char *));
	if (value_printf->specifier == 'u')
		return (ft_itoa(va_arg(*arg, unsigned int)));
	if (value_printf->specifier == 'x')
		return (NULL);
	if (value_printf->specifier == 'X')
		return (NULL);
	if (value_printf->specifier == 'p')
		return (NULL);
	if (value_printf->specifier == 'n')
		return ("");
	if (value_printf->specifier == '%')
		return ("%");
	return (NULL);
}

static char	*ft_get_content(t_value_printf *value_printf, va_list *arg)
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

static int	ft_getflags_and_width(char *str, int i, t_value_printf *value_printf, \
	va_list *arg)
{
	char	*tmp;
	int		j;

	j = 0;
	while (str[i + j] == '-' || str[i + j] == '+' || str[i + j] == ' ' || \
		str[i + j] == '#' || str[i + j] == '0')
	{
		tmp = ft_straddcharendstr(value_printf->flags, str[i + j]);
		free(value_printf->flags);
		if (value_printf->flags == NULL)
			return (-1);
		value_printf->flags = tmp;
		j++;
	}
	if (ft_isdigit(str[i + j]) == 1)
	{
		value_printf->width = ft_atoi(&str[i + j]);
		while (ft_isdigit(str[i + j]) == 1)
			j++;
	}
	else if (str[i + j] == '*')
	{
		value_printf->width = va_arg(*arg, int);
		j++;
	}
	return (j);
}

int	ft_parsing(char *str, int i, t_value_printf *value_printf, va_list *arg)
{
	int	j;

	j = ft_getflags_and_width(str, i, value_printf, arg);
	if (str[i + j] == '.')
	{
		j++;
		if (ft_isdigit(str[i + j]) == 1)
		{
			value_printf->precision = ft_atoi(&str[i + j]);
			while (ft_isdigit(str[i + j] == 1))
				j++;
		}
		else if (str[i + j] == '*')
		{
			value_printf->precision = va_arg(*arg, int);
			j++;
		}
	}
	value_printf->specifier = str[i + j];
	j++;
	value_printf->content = ft_get_content(value_printf, arg);
	return (j);
}
