/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:47 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/21 19:48:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_conditionning_precision_s(t_value_printf *value_printf, \
	int l, char **pre_value, char *s)
{
	if (value_printf->precision < l && value_printf->precision >= 0 \
		&& value_printf->is_precision == 1)
	{
		*pre_value = ft_strndup(s, value_printf->precision);
		l = value_printf->precision;
	}
	else
		*pre_value = ft_strdup(s);
	if (!*pre_value)
		return (-1);
	return (l);
}

static int	ft_printf_s_conditionning(t_value_printf *value_printf, int l, \
	char *s)
{
	char	*pre_value;
	char	*post_value;

	post_value = ft_strdup("");
	if (!post_value)
		return (-1);
	l = ft_printf_conditionning_precision_s(value_printf, l, &pre_value, s);
	if (l < 0)
	{
		free(post_value);
		return (-1);
	}
	l = ft_printf_conditionning_width(value_printf, l, &pre_value, &post_value);
	if (l >= 0)
	{
		ft_putstr(pre_value);
		ft_putstr(post_value);
	}
	free(pre_value);
	free(post_value);
	return (l);
}

static int	ft_printf_s_l(t_value_printf *value_printf, wchar_t *s)
{
	(void)value_printf;
	ft_putwstr(s);
	return (0);
}

int	ft_printf_s(t_value_printf *value_printf, va_list *arg)
{
	char	*s;

	if (ft_strcmp(value_printf->length, "l") == 0)
		return (ft_printf_s_l(value_printf, va_arg(*arg, wchar_t *)));
	s = va_arg(*arg, char *);
	if (s == NULL)
		return (ft_printf_s_conditionning(value_printf, 6, "(null)"));
	return (ft_printf_s_conditionning(value_printf, ft_strlen(s), s));
}
