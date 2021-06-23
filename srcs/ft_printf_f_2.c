/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:05:53 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/23 13:23:22 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_printf_conditionning_width_f_0(t_value_printf *value_printf, \
	char **pre_value, char **post_value)
{
	char	*tmp;

	if (ft_strchr(value_printf->flags, '0') != NULL && \
		ft_strcmp(*post_value, "inf") != 0 && \
		ft_strcmp(*post_value, "nan") != 0)
		tmp = ft_straddcharendstr(*pre_value, '0');
	else
		tmp = ft_straddcharstartstr(*pre_value, ' ');
	return (tmp);
}

int	ft_printf_conditionning_width_f(t_value_printf *value_printf, int l, \
	char **pre_value, char **post_value)
{
	char	*tmp;

	while (value_printf->width > l)
	{
		if (ft_strchr(value_printf->flags, '-') != NULL)
		{
			tmp = ft_straddcharendstr(*post_value, ' ');
			if (!tmp)
				return (-1);
			free(*post_value);
			*post_value = tmp;
		}
		else
		{
			tmp = ft_printf_conditionning_width_f_0(value_printf, pre_value, \
				post_value);
			if (!tmp)
				return (-1);
			free(*pre_value);
			*pre_value = tmp;
		}
		l++;
	}
	return (l);
}

int	ft_printf_conditionning_precision_f(t_value_printf *value_printf, \
	double f, char **post_value)
{
	char	*tmp;

	if (value_printf->precision == 0 && value_printf->is_precision == 0)
		value_printf->precision = 6;
	tmp = ft_nftoa(f, value_printf->precision);
	if (!tmp)
		return (-1);
	free(*post_value);
	*post_value = tmp;
	return (ft_strlen(*post_value));
}

static int	ft_printf_f_conditionning_2(t_value_printf *value_printf, \
	double *f, char ***value)
{
	int	l;
	int	tmpl;

	l = ft_printf_conditionning_precision_f(value_printf, *f, &(*value)[1]);
	if (l < 0)
		return (l);
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

int	ft_printf_f_conditionning_1(t_value_printf *value_printf, double f)
{
	char	**value;
	int		l;

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
	l = ft_printf_f_conditionning_2(value_printf, &f, &value);
	free(value[0]);
	free(value[1]);
	free(value);
	return (l);
}
