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
    char *tmp;
	if (value_printf->precision < l && value_printf->precision >= 0 \
		&& value_printf->is_precision == 1)
	{
		tmp = ft_strndup(s, value_printf->precision);
		l = value_printf->precision;
	}
	else
		tmp = ft_strdup(s);
	if (!tmp)
		return (-1);
    free(*pre_value);
    *pre_value = tmp;
	return (l);
}

static int    ft_printf_s_conditionning_2(t_value_printf *value_printf, \
    char *s, char ***value)
{
    int l;

    l = ft_strlen(s);
    l = ft_printf_conditionning_precision_s(value_printf, l, &(*value)[0], s);
    if (l < 0)
        return (l);
    l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], &(*value)[1]);
    if (l < 0)
        return (l);
    ft_putstr((*value)[0]);
    ft_putstr((*value)[1]);
    return (l);
}

static int	ft_printf_s_conditionning_1(t_value_printf *value_printf, \
	char *s)
{
	char    **value;
    int     l;

	value = malloc(sizeof(char **) * 2);
    if (!value)
        return (-1);
    value[0] = ft_strdup("");
    if (!value[0])
    {
        free(value);
        return (-1);
    }
    value[1] = ft_strdup("");
    if (!value[1])
    {
        free(value[0]);
        free(value);
        return (-1);
    }
    l = ft_printf_s_conditionning_2(value_printf, s, &value);
    free(value[0]);
    free(value[1]);
    free(value);
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
		return (ft_printf_s_conditionning_1(value_printf, "(null)"));
	return (ft_printf_s_conditionning_1(value_printf, s));
}
