/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_printing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:42:18 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:10:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
nb : operateur & --> Retourne 1 si les deux bits de même poids sont à 1
	ex :9 & 12 (1001 & 1100) --> 8 (1000)

nb : operateur >> --> Décale les bits vers la droite (divise par 2 à chaque 
						décalage). Les zéros qui sortent à droite sont perdus, 
						tandis que le bit non nul de poids plus fort est 
						recopié à gauche
	ex : 6 >> 1 (0110 >> 1)	--> 3 (0011)

UTF-8 is a specific scheme for mapping a sequence of 1-4 bytes to a number 
from 0x000000 to 0x10FFFF

nb : left -> hexadecimal, right -> binary

UTF-8 is a specific scheme for mapping a sequence of 1-4 bytes to a number
	from 0x000000 to 0x10FFFF:

00000000 -- 0000007F: 	0xxxxxxx
00000080 -- 000007FF: 	110xxxxx 10xxxxxx
00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

The x's are bits to be extracted from the sequence and glued together to
	form the final number.

sources : https://www.cprogramming.com/tutorial/unicode.html

can be treated as :
c <= 0000007F : c;
c <= 000007FF : c >> 6 + 11000000;
				c & 00111111 + 10000000;
c <= 0000FFFF : c >> 12 + 11100000; 
				c >> 6 & 00111111 + 10000000;
				c & 00111111 + 10000000;
c <= 001FFFFF : c >> 18 + 11110000;
				c >> 12 & 00111111 + 10000000;
				c >> 6 & 00111111 + 10000000;
				c & 00111111 + 10000000;

or :
c <=      127 : c;
c <=     2047 : c >> 6 + 192;
				c & 63 + 128;
c <=    65535 : c >> 12 + 224; 
				c >> 6 & 63 + 128;
				c & 63 + 128;
c <=  2097151 : c >> 18 + 240;
				c >> 12 & 63 + 128;
				c >> 6 & 63 + 128;
				c & 63 + 128;
*/

void	ft_putwchar(wint_t c)
{
	if (c <= 127)
		ft_putchar(c);
	else if (c <= 2047)
	{
		ft_putchar((c >> 6) + 192);
		ft_putchar((c & 63) + 128);
	}
	else if (c <= 65535)
	{
		ft_putchar((c >> 12) + 224);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
	}
	else if (c <= 2097151)
	{
		ft_putchar((c >> 18) + 240);
		ft_putchar(((c >> 12) & 63) + 128);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
	}
}

void	ft_putwstr(wchar_t *s)
{
	int	i;

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
