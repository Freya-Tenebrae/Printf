/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/15 13:15:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_i(t_value_printf *value_printf, long long i)
{
	(void)value_printf;

	ft_putstr_fd(ft_itoa(i), 1);
	return (0);
}
