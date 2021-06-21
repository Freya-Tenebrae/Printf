/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:00:44 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/21 17:00:26 by cmaginot         ###   ########.fr       */
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

char	*ft_itoa_power(int power_ten)
{
	char	*str;

	if (power_ten == 0)
		return (ft_strdup("+00"));
	str = malloc(sizeof(char) * 4);
	if (!str)
		return (NULL);
	if (power_ten < 0)
	{
		power_ten *= -1;
		str[0] = '-';
	}
	else
		str[0] = '+';
	str[1] = '0' + power_ten / 10;
	str[2] = '0' + power_ten % 10;
	str[3] = '\0';
	return (str);
}

char	*ft_nftoa(double f, int precision)
{
	unsigned long long	nb;
	int					len;
	double				tmpnb;
	int					i;
	char				*str;
	unsigned long long	nb_decimal;

	if (f != f)
		return (ft_strdup ("nan"));
	if (f != 0 && (f < -DBL_MAX || (f > -DBL_MIN && f < DBL_MIN) \
		|| f > DBL_MAX))
		return (ft_strdup ("inf"));
	if (f < 0)
		f *= -1;
	nb = (long long)f;
	len = ft_getlen_ll(nb, 10);
	if (precision == 0)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		str[len] = '\0';
		tmpnb = (f * 10) - (nb * 10);
		if (tmpnb > 5)
			nb++;
		else if (tmpnb == 5 && nb % 2 != 0)
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
			return (NULL);
		str[len + precision + 1] = '\0';
		f = f - nb;
		i = 0;
		while (i++ < precision)
			f *= 10;
		nb_decimal = (long long)f;
		tmpnb = (f * 10) - (nb_decimal * 10);
		if (tmpnb > 5)
			nb_decimal++;
		else if (tmpnb == 5 && nb_decimal % 2 != 0)
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
