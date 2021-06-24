/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:47 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/24 05:37:50 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_sw_conditionning_2(t_value_printf *value_printf, \
	wchar_t *ws, char ***value)
{
	int	l;

	l = ft_wstrlen(ws);
	l = ft_printf_conditionning_precision_ws(value_printf, l, &ws);
	if (l < 0)
		return (l);
	l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	ft_putwstr(ws);
	ft_putstr((*value)[1]);
	free(ws);
	return (l);
}

static int	ft_printf_sw_conditionning_1(t_value_printf *value_printf, \
	wchar_t *ws)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_sw_conditionning_2(value_printf, ws, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

static int	ft_printf_s_conditionning_2(t_value_printf *value_printf, \
	char *s, char ***value)
{
	int	l;

	l = ft_strlen(s);
	l = ft_printf_conditionning_precision_s(value_printf, l, &(*value)[0], s);
	if (l < 0)
		return (l);
	l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	ft_putstr((*value)[1]);
	return (l);
}

static int	ft_printf_s_conditionning_1(t_value_printf *value_printf, \
	char *s)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_s_conditionning_2(value_printf, s, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_s(t_value_printf *value_printf, va_list *arg)
{
	char	*s;
	wchar_t	*ws;

	if (ft_strcmp(value_printf->length, "l") == 0)
	{
		ws = va_arg(*arg, wchar_t *);
		if (ws == NULL)
			return (ft_printf_s_conditionning_1(value_printf, "(null)"));
		return (ft_printf_sw_conditionning_1(value_printf, ws));
	}
	s = va_arg(*arg, char *);
	if (s == NULL)
		return (ft_printf_s_conditionning_1(value_printf, "(null)"));
	return (ft_printf_s_conditionning_1(value_printf, s));
}
