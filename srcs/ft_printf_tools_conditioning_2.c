/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_conditioning_2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 03:58:00 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/24 05:38:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_conditionning_precision_ws(t_value_printf *value_printf, \
	int l, wchar_t **ws)
{
	wchar_t	*tmp;

	if (value_printf->precision < l && value_printf->precision >= 0 \
		&& value_printf->is_precision == 1)
	{
		tmp = ft_wstrndup(*ws, value_printf->precision);
		l = value_printf->precision;
	}
	else
		tmp = ft_wstrdup(*ws);
	if (!tmp)
		return (-1);
	*ws = tmp;
	return (l);
}

int	ft_printf_conditionning_precision_s(t_value_printf *value_printf, \
	int l, char **pre_value, char *s)
{
	char	*tmp;

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
