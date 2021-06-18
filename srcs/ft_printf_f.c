/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:49:38 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/18 12:06:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_conditionning_width_f(t_value_printf *value_printf, \
	int l, char **pre_value, char **post_value)
{
	char	*tmp;

	while (value_printf->width > l)
	{
		if (ft_strchr(value_printf->flags, '-') != NULL)
		{
			tmp = ft_straddcharendstr(*post_value, ' ');
			free(*post_value);
			*post_value = tmp;
		}
		else
		{
			if (ft_strchr(value_printf->flags, '0') != NULL)
				tmp = ft_straddcharendstr(*pre_value, '0');
			else
				tmp = ft_straddcharstartstr(*pre_value, ' ');
			free(*pre_value);
			*pre_value = tmp;
		}
		l++;
	}
	return (l);
}

static int	ft_printf_conditionning_precision_f(t_value_printf *value_printf, \
	double f, char **post_value)
{
	char		*tmp;

	if (value_printf->precision == 0 && value_printf->is_precision == 0)
		value_printf->precision = 6;
	tmp = ft_nftoa(f, value_printf->precision);
	free(*post_value);
	*post_value = tmp;
	return (ft_strlen(*post_value));

}

static int	ft_printf_f_conditionning(t_value_printf *value_printf, int l, \
	double f)
{
	char	*pre_value;
	char	*post_value;

	pre_value = ft_strdup("");
	post_value = ft_strdup("");
	l = ft_printf_conditionning_precision_f(value_printf, f, &post_value);
	l += ft_printf_conditionning_sign(value_printf, (long long *)&f, &pre_value);
	l = ft_printf_conditionning_width_f(value_printf, l, &pre_value, &post_value);
	ft_putstr(pre_value);
	ft_putstr(post_value);
	free(pre_value);
	free(post_value);
	return (l);
}

int	ft_printf_f(t_value_printf *value_printf, va_list *arg)
{
	double	f;

	f = va_arg(*arg, double);
	return (ft_printf_f_conditionning(value_printf, 0, f));
}