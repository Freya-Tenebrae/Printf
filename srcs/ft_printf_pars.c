/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:17:59 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/14 13:40:27 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_flags(char *str, int i, t_value_printf *value_printf)
{
	char	*tmp;
	int		j;

	j = 0;
	while (str[i + j] == '-' || str[i + j] == '+' || str[i + j] == ' ' || \
		str[i + j] == '#' || str[i + j] == '0')
	{
		tmp = ft_straddcharendstr(value_printf->flags, str[i + j]);
		free(value_printf->flags);
		if (tmp == NULL)
			return (-1);
		value_printf->flags = tmp;
		j++;
	}
	return (j);
}

static int 	ft_get_width(char *str, int i, t_value_printf *value_printf, \
	va_list *arg)
{
	int		j;
	char	*tmp;

	j = 0;
	if (ft_isdigit(str[i + j]) == 1)
	{
		value_printf->width = ft_atoi(&str[i + j]);
		while (ft_isdigit(str[i + j]) == 1)
			j++;
	}
	else if (str[i + j] == '*')
	{
		value_printf->width = va_arg(*arg, int);
		if (value_printf->width < 0)
		{
			value_printf->width *= -1;
			tmp = ft_straddcharendstr(value_printf->flags, '-');
			free(value_printf->flags);
			if (tmp == NULL)
				return (-1);
			value_printf->flags = tmp;
		}
		j++;
	}
	return (j);
}

static int	ft_get_precision(char *str, int i, t_value_printf *value_printf, \
	va_list *arg)
{
	int		j;

	j = 0;
	if (str[i + j] == '.')
	{
		j++;
		if (ft_isdigit(str[i + j]) == 1)
		{
			value_printf->precision = ft_atoi(&str[i + j]);
			while (ft_isdigit(str[i + j]) == 1)
				j++;
		}
		else if (str[i + j] == '*')
		{
			value_printf->precision = va_arg(*arg, int);
			j++;
		}
	}
	return (j);
}

static int	ft_get_length(char *str, int i, t_value_printf *value_printf)
{
	int		j;

	j = 0;
	if (str[i + j] == 'l' || str[i + j] == 'h')
	{
		j++;
		if (str[i + j] == 'l' || str[i + j] == 'h')
			j++;
		value_printf->length = ft_strndup(&str[i], j);
	}
	else
		value_printf->length = ft_strdup("");
	if (!value_printf->length)
	{
		free(value_printf->flags);
		return (-1);
	}
	return (j);
}

int	ft_parsing(char *str, int *i, t_value_printf *value_printf, va_list *arg)
{
	int	tmpi;

	tmpi = ft_get_flags(str, *i, value_printf);
	if (tmpi < 0)
		return (-1);
	*i += tmpi;
	tmpi = ft_get_width(str, *i, value_printf, arg);
	if (tmpi < 0)
		return (-1);
	*i += tmpi;
	*i += ft_get_precision(str, *i, value_printf, arg);
	tmpi = ft_get_length(str, *i, value_printf);
	if (tmpi < 0)
		return (-1);
	*i += tmpi;
	value_printf->specifier = str[*i];
	*i += 1;
	return (ft_get_content(value_printf, arg));
}
