/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:00:44 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/18 12:48:01 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_getlen_ll(long long n, int i)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= i;
		len++;
	}
	return (len);
}

int	ft_getlen_ull(unsigned long long n, int i)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= i;
		len++;
	}
	return (len);
}

char	*ft_nftoa(double f, int precision)
{
	long long	nb;
	int			len;
	int			i;
	char		*str;
	long long	nb_decimal;

	if (f < 0)
		f *= -1;
	nb = (long long)f;
	len = ft_getlen_ll(nb, 10);
	if (precision == 0)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		str[len] = '\0';
		i = (long long)(f * 10) - (nb * 10);
		if (i >= 5)
			nb++;
		while (0 < len)
		{
			str[--len] = ('0' + (nb % 10));
			nb /= 10;
		}
	}
	else
	{
		str = malloc(sizeof(char) * (len + precision + 2));
		if (!str)
			return (0);
		str[len + precision + 1] = '\0';
		f = f - nb;
		i = 0;
		while (i++ < precision)
			f *= 10;
		nb_decimal = (long long)f;
		i = (long long)(f * 10) - (nb_decimal * 10);
		if(i >= 5)
			nb_decimal++;
		while (0 < precision)
		{
			str[len + precision--] = ('0' + (nb_decimal % 10));
			nb_decimal /= 10;
		}
		str[len + precision--] = '.';
		while (0 < len)
		{
			str[--len] = ('0' + (nb % 10));
			nb /= 10;
		}
	}
	return (str);
}
