/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_o.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:08:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:10:03 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_o_hash(t_value_printf *value_printf, \
	unsigned long long i, char **tmp)
{
	if (ft_strchr(value_printf->flags, '#') != NULL && i != 0)
	{
		*tmp = ft_strdup("0");
		if (!*tmp)
			return (-1);
		return (0);
	}
	*tmp = NULL;
	return (0);
}

static int	ft_printf_o_conditionning_2(t_value_printf *value_printf, \
	unsigned long long *i, char ***value)
{
	int	l;

	l = ft_getlen_ull(*i, 8);
	l = ft_printf_conditionning_precision(value_printf, l, &(*value)[0]);
	if (l < 0)
		return (l);
	if (value_printf->is_precision == 1 && value_printf->precision == 0 \
		&& *i == 0)
		l -= 1;
	if (ft_strchr(value_printf->flags, '#') != NULL && *i != 0)
		l++;
	l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	if (value_printf->is_precision != 1 || value_printf->precision != 0 \
		|| *i != 0)
		ft_putnbr_oct(*i);
	ft_putstr((*value)[1]);
	return (l);
}

static int	ft_printf_o_conditionning_1(t_value_printf *value_printf, \
	unsigned long long i)
{
	char	*tmp;
	char	**value;
	int		l;

	if (ft_printf_o_hash(value_printf, i, &tmp) < 0)
		return (-1);
	if (ft_strchr(value_printf->flags, '#') != NULL && i != 0)
	{
		tmp = ft_strdup("0");
		if (!tmp)
			return (-1);
	}
	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	if (tmp != NULL)
	{
		free(value[0]);
		value[0] = tmp;
	}
	l = ft_printf_o_conditionning_2(value_printf, &i, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_specifier_o(t_value_printf *value_printf, va_list *arg)
{
	if (ft_strcmp(value_printf->length, "hh") == 0)
		return (ft_printf_o_conditionning_1(value_printf, \
			(unsigned char)va_arg(*arg, unsigned int)));
	else if (ft_strcmp(value_printf->length, "h") == 0)
		return (ft_printf_o_conditionning_1(value_printf, \
			(unsigned short)va_arg(*arg, unsigned int)));
	else if (ft_strcmp(value_printf->length, "l") == 0)
		return (ft_printf_o_conditionning_1(value_printf, \
			va_arg(*arg, unsigned long)));
	else if (ft_strcmp(value_printf->length, "ll") == 0)
		return (ft_printf_o_conditionning_1(value_printf, \
			va_arg(*arg, unsigned long long)));
	return (ft_printf_o_conditionning_1(value_printf, \
		va_arg(*arg, unsigned int)));
}
