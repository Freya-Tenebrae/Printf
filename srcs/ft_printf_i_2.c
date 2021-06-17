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

int	ft_printf_i_conditionning(t_value_printf *value_printf, int l, long long i)
{
	char	*pre_value;
	char	*post_value;

	pre_value = ft_strdup("");
	post_value = ft_strdup("");
	l = ft_printf_conditionning_precision(value_printf, l, &pre_value);
	l += ft_printf_conditionning_sign(value_printf, &i, &pre_value);
	if (value_printf->is_precision == 1 && value_printf->precision == 0 \
		&& i == 0)
		l--;
	l = ft_printf_conditionning_width(value_printf, l, &pre_value, &post_value);
	ft_putstr(pre_value);
	if (value_printf->is_precision != 1 || value_printf->precision != 0 \
		|| i != 0)
		ft_putnbr_ull(i);
	ft_putstr(post_value);
	free(pre_value);
	free(post_value);
	return (l);
}
