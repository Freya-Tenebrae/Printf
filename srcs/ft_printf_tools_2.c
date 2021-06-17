/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:42:18 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/17 16:15:41 by cmaginot         ###   ########.fr       */
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

void	ft_putnbr_oct(unsigned long long n)
{
	if (n > 7)
		ft_putnbr_oct(n / 8);
	ft_putchar((n % 8) + '0');
}

void	ft_putnbr_ull(unsigned long long n)
{
	if (n > 9)
		ft_putnbr_ull(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putnbr_hex(unsigned long long n, int is_upper)
{
	if (n > 15)
		ft_putnbr_hex(n / 16, is_upper);
	if (n % 16 > 9 && n % 16 < 16)
	{
		if (is_upper == 0)
			ft_putchar((n % 16) - 10 + 'a');
		else
			ft_putchar((n % 16) - 10 + 'A');
	}
	else
		ft_putchar((n % 16) + '0');
}
