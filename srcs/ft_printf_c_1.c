/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:49 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/22 11:20:00 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_c(t_value_printf *value_printf, va_list *arg)
{
	char	c;

	if (ft_strcmp(value_printf->length, "l") == 0)
	{
		if (arg == NULL)
			return (ft_printf_cw_conditionning_1(value_printf, (wint_t) u'%'));
		else
			return (ft_printf_cw_conditionning_1(value_printf, va_arg(*arg, wint_t)));
	}
	if (arg == NULL)
		c = '%';
	else
		c = (char)va_arg(*arg, int);
	return (ft_printf_c_conditionning_1(value_printf, c));
}
