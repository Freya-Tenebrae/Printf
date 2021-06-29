/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_e.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:30:28 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/29 09:05:25 by cmaginot         ###   ########.fr       */
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
	if (!tmp1)
		return (-1);
	l = ft_strlen(tmp1) + 1;
	tmp2 = ft_straddcharstartstr(tmp1, 'e' + (is_upper * -32));
	free(tmp1);
	if (!tmp2)
		return (-1);
	tmp1 = ft_strjoin(*post_value, tmp2);
	free(tmp2);
	if (!tmp1)
		return (-1);
	free(*post_value);
	*post_value = tmp1;
	return (l);
}

static int	ft_printf_e_conditionning_2(t_value_printf *value_printf, \
	double *f, char ***value, int is_upper)
{
	int	l;
	int	tmpl;
	int	power_ten;

	power_ten = ft_transform_f_into_e(f);
	l = ft_printf_conditionning_precision_f(value_printf, *f, &(*value)[1]);
	if (l < 0)
		return (l);
	tmpl = ft_printf_conditionning_put_e(&(*value)[1], is_upper, power_ten);
	if (tmpl < 0)
		return (tmpl);
	l += tmpl;
	tmpl = ft_printf_conditionning_sign(value_printf, (long long *)f, \
		&(*value)[0]);
	if (tmpl < 0)
		return (tmpl);
	l += tmpl;
	l = ft_printf_conditionning_width_f(value_printf, l, &(*value)[0], \
		&(*value)[1]);
	if (l < 0)
		return (l);
	ft_putstr((*value)[0]);
	ft_putstr((*value)[1]);
	return (l);
}

int	ft_printf_e_conditionning_1(t_value_printf *value_printf, \
	double f, int is_upper)
{
	char	**value;
	int		l;

	if (ft_init_value_conditionning(&value) != 0)
		return (-1);
	l = ft_printf_e_conditionning_2(value_printf, &f, &value, is_upper);
	ft_free_value_conditionning(&value);
	return (l);
}

int	ft_printf_specifier_e(t_value_printf *value_printf, va_list *arg, \
	int is_upper)
{
	return (ft_printf_e_conditionning_1(value_printf, va_arg(*arg, double), \
		is_upper));
}
