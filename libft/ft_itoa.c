/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:03:59 by cmaginot          #+#    #+#             */
/*   Updated: 2021/04/19 16:41:41 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int			len;
	int			i;
	long int	nb;
	char		*str;

	nb = n;
	len = ft_getlen(nb);
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (0);
	str[len] = '\0';
	i = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb *= -1;
	}
	while (i < len)
	{
		str[--len] = ('0' + (nb % 10));
		nb /= 10;
	}
	return (str);
}
