/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:17:59 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/24 07:29:45 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_get_flags(char **pstr, t_value_printf *value_printf)
{
	char	*tmp;

	while (**pstr == '-' || **pstr == '+' || **pstr == ' ' || \
		**pstr == '#' || **pstr == '0')
	{
		tmp = ft_straddcharendstr(value_printf->flags, **pstr);
		free(value_printf->flags);
		if (tmp == NULL)
			return (-1);
		value_printf->flags = tmp;
		*pstr += 1;
	}
	return (0);
}

static int 	ft_get_width(char **pstr, t_value_printf *value_printf, \
	va_list *arg)
{
	char	*tmp;

	if (ft_isdigit(**pstr) == 1)
	{
		value_printf->width = ft_atoi(*pstr);
		while (ft_isdigit(**pstr) == 1)
			*pstr += 1;
	}
	else if (**pstr == '*')
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
		*pstr += 1;
	}
	return (0);
}

static int	ft_get_precision(char **pstr, t_value_printf *value_printf, \
	va_list *arg)
{
	if (**pstr == '.')
	{
		value_printf->is_precision = 1;
		*pstr += 1;
		if (ft_isdigit(**pstr) == 1)
		{
			value_printf->precision = ft_atoi(*pstr);
			while (ft_isdigit(**pstr) == 1)
				*pstr += 1;
		}
		else if (**pstr == '*')
		{
			value_printf->precision = va_arg(*arg, int);
			*pstr += 1;
		}
	}
	return (0);
}

static int	ft_get_length(char **pstr, t_value_printf *value_printf)
{
	int	i;

	i = 0;
	if ((*pstr)[i] == 'l' || (*pstr)[i] == 'h')
	{
		i++;
		if ((*pstr)[i] == 'l' || (*pstr)[i] == 'h')
			i++;
		value_printf->length = ft_strndup(*pstr, i);
	}
	else
		value_printf->length = ft_strdup("");
	if (!value_printf->length)
	{
		free(value_printf->flags);
		return (-1);
	}
	while (i-- > 0)
		*pstr += 1;
	return (0);
}

int	ft_parsing(char **pstr, t_value_printf *value_printf, va_list *arg)
{
	if (ft_get_flags(pstr, value_printf) < 0)
		return (-1);
	if (ft_get_width(pstr, value_printf, arg) < 0)
		return (-1);
	if (ft_get_precision(pstr, value_printf, arg) < 0)
		return (-1);
	if (ft_get_length(pstr, value_printf) < 0)
		return (-1);
	value_printf->specifier = **pstr;
	*pstr += 1;
	return (ft_get_content(value_printf, arg));
}
