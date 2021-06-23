/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:00:44 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/23 13:24:28 by cmaginot         ###   ########.fr       */
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

int	ft_wstrlen(const wchar_t *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
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
