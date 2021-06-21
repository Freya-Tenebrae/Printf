/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:30:28 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/21 14:54:42 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_transform_f_into_e(double *f)
{
	int	i;

	i = 0;
	if (*f == 0 || *f != *f || (*f != 0 && (*f < -DBL_MAX || (*f > -DBL_MIN && \
								*f < DBL_MIN) || *f > DBL_MAX)))
		return (i);
	while (*f < 1 && *f > -1)
	{
		*f *= 10;
		i -= 1;
	}
	while (*f >= 10 || *f <= -10)
	{
		*f /= 10;
		i += 1;
	}
	return (i);
}

static int	ft_printf_conditionning_put_e(char **post_value, int is_upper, \
	int power_ten)
{
	char	*tmp1;
	char	*tmp2;
	int		l;

	if (ft_strcmp(*post_value, "inf") == 0 || \
		ft_strcmp(*post_value, "nan") == 0)
		return (0);
	tmp1 = ft_itoa_power(power_ten);
	l = ft_strlen(tmp1) + 1;
	tmp2 = ft_straddcharstartstr(tmp1, 'e' + (is_upper * -32));
	free(tmp1);
	tmp1 = ft_strjoin(*post_value, tmp2);
	free(*post_value);
	free(tmp2);
	*post_value = tmp1;
	return (l);
}

static int	ft_printf_e_conditionning(t_value_printf *value_printf, int l, \
	double f, int is_upper)
{
	char	*pre_value;
	char	*post_value;
	int		power_ten;

	power_ten = ft_transform_f_into_e(&f);
	pre_value = ft_strdup("");
	post_value = ft_strdup("");
	l = ft_printf_conditionning_precision_f(value_printf, f, &post_value);
	l += ft_printf_conditionning_put_e(&post_value, is_upper, power_ten);
	l += ft_printf_conditionning_sign(value_printf, (long long *)&f, \
		&pre_value);
	l = ft_printf_conditionning_width_f(value_printf, l, &pre_value, \
		&post_value);
	ft_putstr(pre_value);
	ft_putstr(post_value);
	free(pre_value);
	free(post_value);
	return (l);
}

int	ft_printf_e(t_value_printf *value_printf, va_list *arg, int is_upper)
{
	double	f;

	f = va_arg(*arg, double);
	return (ft_printf_e_conditionning(value_printf, 0, f, is_upper));
}
