/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:08:30 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/15 12:25:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_getlen(int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= 8;
		len++;
	}
	return (len);
}

static char	*ft_itoa_octale(int n)
{
	int			len;
	long int	nb;
	char		*str;

	nb = n;
	len = ft_getlen(nb);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (0 < len)
	{
		str[--len] = ('0' + (nb % 8));
		nb /= 8;
	}
	return (str);
}


int	ft_printf_o(t_value_printf *value_printf, size_t i)
{
	(void)value_printf;
	
	ft_putstr_fd(ft_itoa_octale(i), 1);
	return (0);
}