/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:08:32 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/15 12:26:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_getlen(int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa_hexadecimal(size_t n)
{
	int			len;
	char		*str;
	int			nb;

	len = ft_getlen(n);
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

int	ft_printf_x(t_value_printf *value_printf, size_t i, int maj)
{
	char	*str;
	int		j;

	(void)value_printf;

	str = ft_itoa_hexadecimal(i);
	j = 0;
	if (maj == 1)
	{
		while (str[j] != '\0')
			ft_toupper(str[j]);
	}
	ft_putstr_fd(str, 1);
	return (0);
}