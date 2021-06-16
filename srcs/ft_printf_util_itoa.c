/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_itoa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:42:18 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/16 12:28:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* ajouter itoa long long + itoa decimal + ...;*/

static int	ft_getunsignedlen(unsigned long long n, int i)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= i;
		len++;
	}
	return (len);
}

char	*ft_itoa_hexadecimal(unsigned long long n)
{
	int					len;
	char				*str;
	unsigned long long	nb;

	len = ft_getunsignedlen(n, 16);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (0 < len)
	{
		nb = n % 16;
		if (nb < 10)
			str[--len] = ('0' + nb);
		else
			str[--len] = ('a' + (nb - 10));
		n /= 16;
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned long long n)
{
	int			len;
	char		*str;

	len = ft_getunsignedlen(n, 10);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (0 < len)
	{
		str[--len] = ('0' + (n % 10));
		n /= 10;
	}
	return (str);
}

char	*ft_itoa_octale(unsigned long long n)
{
	int			len;
	char		*str;

	len = ft_getunsignedlen(n, 8);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (0 < len)
	{
		str[--len] = ('0' + (n % 8));
		n /= 8;
	}
	return (str);
}
