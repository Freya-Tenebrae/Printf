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

static int	ft_printf_cw_conditionning(t_value_printf *value_printf, int l, \
	wint_t c)
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
	l = ft_printf_conditionning_width(value_printf, l, &pre_value, &post_value);
	if (l >= 0)
	{
		ft_putstr(pre_value);
		ft_putwchar(c);
		ft_putstr(post_value);
	}
	free(pre_value);
	free(post_value);
	return (l);
}

static int	ft_printf_c_conditionning(t_value_printf *value_printf, int l, \
	char c)
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
	l = ft_printf_conditionning_width(value_printf, l, &pre_value, &post_value);
	if (l >= 0)
	{
		ft_putstr(pre_value);
		ft_putchar(c);
		ft_putstr(post_value);
	}
	free(pre_value);
	free(post_value);
	return (l);
}

static int	ft_printf_c_l(t_value_printf *value_printf, wint_t c)
{
	return (ft_printf_cw_conditionning(value_printf, 1, c));
}

int	ft_printf_c(t_value_printf *value_printf, va_list *arg)
{
	char	c;

	if (ft_strcmp(value_printf->length, "l") == 0)
	{
		if (arg == NULL)
			return (ft_printf_c_l(value_printf, (wint_t) u'%'));
		else
			return (ft_printf_c_l(value_printf, va_arg(*arg, wint_t)));
	}
	if (arg == NULL)
		c = '%';
	else
		c = (char)va_arg(*arg, int);
	return (ft_printf_c_conditionning(value_printf, 1, c));
}
