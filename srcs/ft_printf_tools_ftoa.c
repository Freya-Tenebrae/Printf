/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_ftoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:30:50 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:10:23 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_ftoa_do_precision_2(double *f, int precision, int isnegatif, \
	int i)
{
	if (i == 100)
	{
		if (((unsigned long long)(*f) % 2 != 0 && precision == 0))
			*f += 1;
		else if (precision != 0 && precision < 15 && isnegatif == 0)
			*f += 1;
		else if (precision % 2 == 1 && isnegatif == 1)
			*f += 1;
	}
}

static void	ft_ftoa_do_precision_1(double *f, int precision, int isnegatif)
{
	int					i;
	double				fbis;
	unsigned long long	nb;

	fbis = *f;
	nb = (unsigned long long)(fbis * 10);
	if (nb % 10 > 5)
		*f += 1;
	if (nb % 10 == 5)
	{
		i = 1;
		while (i++ < 100)
		{
			fbis = (fbis * 10) - nb;
			nb = (unsigned long long)(fbis * 10);
			if (nb % 10 > 0)
			{
				i = 101;
				*f += 1;
			}
			ft_ftoa_do_precision_2(f, precision, isnegatif, i);
		}
	}
}

static char	*ft_nftoa_putinstr(double f, int len, int precision)
{
	char				*str;
	unsigned long long	nb;

	str = malloc(sizeof(char) * (len + precision + 2));
	if (!str)
		return (NULL);
	str[len + precision + 1] = '\0';
	if (precision == 0)
		str[len] = '\0';
	else
		str[len] = '.';
	nb = (unsigned long long)f;
	while (0 < precision)
	{
		str[len + precision--] = ('0' + (nb % 10));
		nb /= 10;
	}
	while (0 < len)
	{
		str[--len] = ('0' + (nb % 10));
		nb /= 10;
	}
	return (str);
}

char	*ft_nftoa(double f, int precision)
{
	int		len;
	int		i;
	double	fbis;
	int		isnegatif;

	isnegatif = 0;
	if (f != f)
		return (ft_strdup ("nan"));
	if (f != 0 && (f < -DBL_MAX || (f > -DBL_MIN && f < DBL_MIN) \
		|| f > DBL_MAX))
		return (ft_strdup ("inf"));
	if (f < 0)
	{
		isnegatif = 1;
		f *= -1;
	}
	i = 0;
	while (i++ < precision)
		f *= 10;
	ft_ftoa_do_precision_1(&f, precision, isnegatif);
	fbis = f;
	while (--i > 0)
		fbis /= 10;
	len = ft_getlen_ull((unsigned long long)fbis, 10);
	return (ft_nftoa_putinstr(f, len, precision));
}
