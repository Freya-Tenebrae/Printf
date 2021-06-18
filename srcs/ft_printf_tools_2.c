/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:42:18 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/18 10:01:54 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* need to do ft_putwchar & ft_putwstr properly */

void	ft_putwchar(wint_t c)
{
	write(1, &c, 1);
}

void	ft_putwstr(wchar_t *s)
{
	size_t	i;

	i = -1;
	if (s != 0)
		while (s[++i] != '\0')
			ft_putwchar(s[i]);
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
