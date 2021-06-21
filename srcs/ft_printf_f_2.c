/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:05:53 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/21 19:29:49 by cmaginot         ###   ########.fr       */
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
	char		*tmp;

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
	double f, char **pre_value, char **post_value)
{
	int	l;
	int	tmpl;

	l = ft_printf_conditionning_precision_f(value_printf, f, post_value);
	if (l < 0)
		return (l);
	tmpl = ft_printf_conditionning_sign(value_printf, (long long *)&f, \
		pre_value);
	if (tmpl < 0)
		return (tmpl);
	l += tmpl;
	l = ft_printf_conditionning_width_f(value_printf, l, pre_value, \
		post_value);
	if (l < 0)
		return (l);
	ft_putstr(*pre_value);
	ft_putstr(*post_value);
	return (l);
}

int	ft_printf_f_conditionning_1(t_value_printf *value_printf, int l, double f)
{
	char	*pre_value;
	char	*post_value;

	pre_value = ft_strdup("");
	if (!pre_value)
		return (-1);
	post_value = ft_strdup("");
	if (!post_value)
	{
		free(pre_value);
		return (-1);
	}
	l = ft_printf_f_conditionning_2(value_printf, f, &pre_value, &post_value);
	free(pre_value);
	free(post_value);
	return (l);
}
