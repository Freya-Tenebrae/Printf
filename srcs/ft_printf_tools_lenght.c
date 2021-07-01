/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_lenght.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:00:44 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:10:26 by cmaginot         ###   ########.fr       */
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

/*int	ft_wcharlen(const wint_t c)
{
	if (c <= 127)
		return (1);
	if (c <= 2047)
		return (1);
	if (c <= 65535)
		return (1);
	return (4);
}*/

int	ft_wstrlen(const wchar_t *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len ++;
	return (len);
}
