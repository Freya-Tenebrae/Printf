/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:47 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/17 15:43:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_conditionning_precision_s(t_value_printf *value_printf, \
	int l, char **pre_value, char *s)
{
	if (value_printf->precision < l && value_printf->precision >= 0 \
		&& value_printf->is_precision == 1)
	{
		free(*pre_value);
		*pre_value = ft_strndup(s, value_printf->precision);
		l = value_printf->precision;
	}
	return (l);
}

static int	ft_printf_s_conditionning(t_value_printf *value_printf, int l, \
	char *s)
{
	char	*pre_value;
	char	*post_value;

	pre_value = ft_strdup(s);
	post_value = ft_strdup("");
	l = ft_printf_conditionning_precision_s(value_printf, l, &pre_value, s);
	l = ft_printf_conditionning_width(value_printf, l, &pre_value, &post_value);
	ft_putstr(pre_value);
	ft_putstr(post_value);
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
