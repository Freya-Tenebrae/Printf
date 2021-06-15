/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:08:52 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/15 14:49:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_u(t_value_printf *value_printf, unsigned long long i)
{
	(void)value_printf;
	ft_putstr_fd(ft_itoa_unsigned(i), 1);
	return (0);
}
