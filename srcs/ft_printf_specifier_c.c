/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:49 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:09:49 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_cw_conditionning_2(t_value_printf *value_printf, \
	wint_t c, char ***value)
{
	int	l;

	l = ft_printf_conditionning_width(value_printf, 1, &(*value)[0], \
		&(*value)[1]);
	if (l >= 0)
	{
		ft_putstr((*value)[0]);
		ft_putwchar(c);
		ft_putstr((*value)[1]);
	}
	return (l);
}

static int	ft_printf_cw_conditionning_1(t_value_printf *value_printf, \
	wint_t c)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_cw_conditionning_2(value_printf, c, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

static int	ft_printf_c_conditionning_2(t_value_printf *value_printf, \
	char c, char ***value)
{
	int	l;

	l = ft_printf_conditionning_width(value_printf, 1, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	ft_putchar(c);
	ft_putstr((*value)[1]);
	return (l);
}

static int	ft_printf_c_conditionning_1(t_value_printf *value_printf, \
	char c)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_c_conditionning_2(value_printf, c, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_specifier_c(t_value_printf *value_printf, va_list *arg)
{
	char	c;

	if (ft_strcmp(value_printf->length, "l") == 0)
	{
		if (arg == NULL)
			return (ft_printf_cw_conditionning_1(value_printf, (wint_t) u'%'));
		else
			return (ft_printf_cw_conditionning_1(value_printf, \
				va_arg(*arg, wint_t)));
	}
	if (arg == NULL)
		c = '%';
	else
		c = (char)va_arg(*arg, int);
	return (ft_printf_c_conditionning_1(value_printf, c));
}
