/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/16 12:29:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_i(t_value_printf *value_printf, long long i)
{
	(void)value_printf;
	ft_putstr_fd(ft_itoa(i), 1);
	return (0);
}

/*int	ft_printf_i(t_value_printf *value_printf, va_list *arg)
{
	void	*i;
	char	*tmp;

	(void)value_printf;
	tmp = ft_strchr(value_printf->length, 'l');
	if (tmp != NULL)
	{
		tmp++;
		tmp = ft_strchr(value_printf->length, 'l');
		if (tmp != NULL)
		{
			i = malloc(sizeof(long long));
			i = &(long long)va_arg(*arg, long long);
		}
		else
		{
			i = &va_arg(*arg, long);
		}
	}
	else
	{
		tmp = ft_strchr(value_printf->length, 'h');
		if (tmp != NULL)
		{
			tmp++;
			tmp = ft_strchr(value_printf->length, 'h');
			if (tmp != NULL)
				i = &va_arg(*arg, signed char);
			else
				i = &va_arg(*arg, short);
		}
		else
			i = &va_arg(*arg, int);
	}
	ft_putstr_fd(ft_itoa(*i), 1);
	return (0);
}*/