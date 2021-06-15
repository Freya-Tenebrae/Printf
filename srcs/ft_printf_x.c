/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:08:32 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/15 14:49:07 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_x(t_value_printf *value_printf, unsigned long long i, int maj)
{
	char	*str;
	int		j;

	(void)value_printf;
	str = ft_itoa_hexadecimal(i);
	j = 0;
	if (maj == 1)
	{
		while (str[j] != '\0')
			ft_toupper(str[j]);
	}
	ft_putstr_fd(str, 1);
	return (0);
}
