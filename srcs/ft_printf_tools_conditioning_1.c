/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_conditioning_1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:07:14 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:10:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printf_conditionning_sign_pos(t_value_printf *value_printf, \
	char **pre_value)
{
	char	*tmp;

	if (ft_strchr(value_printf->flags, '+') != NULL || \
				  ft_strchr(value_printf->flags, ' ') != NULL)
	{
		if (ft_strchr(value_printf->flags, '+') != NULL)
			tmp = ft_straddcharstartstr(*pre_value, '+');
		else
			tmp = ft_straddcharstartstr(*pre_value, ' ');
		if (!tmp)
			return (-1);
		free(*pre_value);
		*pre_value = tmp;
		return (1);
	}
	return (0);
}

int	ft_printf_conditionning_sign(t_value_printf *value_printf, long long *i, \
	char **pre_value)
{
	char	*tmp;

	if (*i < 0)
	{
		tmp = ft_straddcharstartstr(*pre_value, '-');
		if (!tmp)
			return (-1);
		free(*pre_value);
		*pre_value = tmp;
		*i *= -1;
		return (1);
	}
	return (ft_printf_conditionning_sign_pos(value_printf, pre_value));
}

int	ft_printf_conditionning_precision(t_value_printf *value_printf, int l, \
	char **pre_value)
{
	char	*tmp;

	while (value_printf->precision > l)
	{
		tmp = ft_straddcharendstr(*pre_value, '0');
		if (!tmp)
			return (-1);
		free(*pre_value);
		*pre_value = tmp;
		l++;
	}
	return (l);
}

static char	*ft_printf_conditionning_width_0(t_value_printf *value_printf, \
	char **pre_value)
{
	char	*tmp;

	if (ft_strchr(value_printf->flags, '0') != NULL && \
		(value_printf->is_precision == 0 || value_printf->precision < 0 || \
		value_printf->specifier == '%'))
		tmp = ft_straddcharendstr(*pre_value, '0');
	else
		tmp = ft_straddcharstartstr(*pre_value, ' ');
	return (tmp);
}

int	ft_printf_conditionning_width(t_value_printf *value_printf, int l, \
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
			tmp = ft_printf_conditionning_width_0(value_printf, pre_value);
			if (!tmp)
				return (-1);
			free(*pre_value);
			*pre_value = tmp;
		}
		l++;
	}
	return (l);
}
