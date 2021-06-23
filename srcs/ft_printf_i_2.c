/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:09:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/17 16:39:05 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int    ft_printf_i_conditionning_2(t_value_printf *value_printf, \
    long long *i, char ***value)
{
    int    tmpl;
    int    l;

    l = ft_getlen_ll(*i, 10);
    l = ft_printf_conditionning_precision(value_printf, l, &(*value)[0]);
    if (l < 0)
        return (l);
    tmpl = ft_printf_conditionning_sign(value_printf, i, &(*value)[0]);
    if (tmpl < 0)
        return (tmpl);
    l += tmpl;
    if (value_printf->is_precision == 1 && value_printf->precision == 0 \
        && *i == 0)
        l-= 1;
    l = ft_printf_conditionning_width(value_printf, l, &(*value)[0], &(*value)[1]);
    if (l < 0)
        return (l);
    ft_putstr((*value)[0]);
    if (value_printf->is_precision != 1 || value_printf->precision != 0 \
        || *i != 0)
        ft_putnbr_ull(*i);
    ft_putstr((*value)[1]);
    return (l);
}

int	ft_printf_i_conditionning_1(t_value_printf *value_printf, long long i)
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
    l = ft_printf_i_conditionning_2(value_printf, &i, &value);
    free(value[0]);
    free(value[1]);
    free(value);
    return (l);
}
