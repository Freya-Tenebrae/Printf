/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_%.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:49 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:09:46 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_percent_conditionning_2(t_value_printf *value_printf, \
	char ***value)
{
	int	l;

	l = ft_printf_conditionning_width(value_printf, 1, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	ft_putchar('%');
	ft_putstr((*value)[1]);
	return (l);
}

static int	ft_printf_percent_conditionning_1(t_value_printf *value_printf)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_percent_conditionning_2(value_printf, &value);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_specifier_percent(t_value_printf *value_printf)
{
	return (ft_printf_percent_conditionning_1(value_printf));
}
