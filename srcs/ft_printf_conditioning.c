/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conditioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:07:14 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/19 15:47:02 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
TODO :
		--> secure all memory allocation
		-do other specifier, make fonction for them and not atoi or other ...
		do the flag : #
		flag l/ll/h/hh failed on ncs
		specifier : pnfge
*/

int	ft_printf_conditionning_sign(t_value_printf *value_printf, long long *i, \
	char **pre_value)
{
	char	*tmp;

	if (*i < 0)
	{
		tmp = ft_straddcharstartstr(*pre_value, '-');
		free(*pre_value);
		*pre_value = tmp;
		*i *= -1;
		return (1);
	}
	else if (ft_strchr(value_printf->flags, '+') != NULL || \
				  ft_strchr(value_printf->flags, ' ') != NULL)
	{
		if (ft_strchr(value_printf->flags, '+') != NULL)
			tmp = ft_straddcharstartstr(*pre_value, '+');
		else
			tmp = ft_straddcharstartstr(*pre_value, ' ');
		free(*pre_value);
		*pre_value = tmp;
		return (1);
	}
	return (0);
}

int	ft_printf_conditionning_precision(t_value_printf *value_printf, int l, \
	char **pre_value)
{
	char	*tmp;

	while (value_printf->precision > l)
	{
		tmp = ft_straddcharendstr(*pre_value, '0');
		free(*pre_value);
		*pre_value = tmp;
		l++;
	}
	return (l);
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
			free(*post_value);
			*post_value = tmp;
		}
		else
		{
			if (ft_strchr(value_printf->flags, '0') != NULL && \
				(value_printf->is_precision == 0 || \
				value_printf->precision < 0))
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
