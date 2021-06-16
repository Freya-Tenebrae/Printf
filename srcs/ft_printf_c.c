/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:16:49 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/16 12:15:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* int	ft_printf_c(t_value_printf *value_printf, va_list *arg)
{
	void	*c_ptr;
	char	c;

	(void)value_printf;
	if (arg == NULL)
	{
		c = '%';
		c_ptr = &c;
	}
	else if (ft_strchr(value_printf->length, 'l') == NULL)
	{
		c = va_arg(*arg, char);
		c_ptr = &c;
	}
	else
	{
		*c = va_arg(*arg, wint_t);
	}
	ft_putchar_fd(c, 1);
	return (0);
} */

int	ft_printf_c(t_value_printf *value_printf, char c)
{
	(void)value_printf;
	ft_putchar_fd(c, 1);
	return (0);
}
