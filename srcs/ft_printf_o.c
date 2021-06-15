/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:08:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/15 14:40:27 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_o(t_value_printf *value_printf, unsigned long long i)
{
	(void)value_printf;
	
	ft_putstr_fd(ft_itoa_octale(i), 1);
	return (0);
}