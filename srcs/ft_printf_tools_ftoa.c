/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_ftoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:30:50 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/30 21:12:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*static unsigned long long	ft_ftoa_round_up(double f)
{
	unsigned long long	nb;
	double				tmpnb;

	nb = (unsigned long long)f;
	tmpnb = (f * 10) - (nb * 10);
	if (tmpnb > 5)
		return (1);
	if (tmpnb == 5 && nb % 2 != 0)
		return (1);
	if (tmpnb == 5)
	{
		f = f * 10;
		nb = (unsigned long long)f;
		tmpnb = (f * 10) - ((unsigned long long)f * 10);
		if (tmpnb > 5)
			return (1);
		if (tmpnb < 5)
			return (0);
	}
	return (0);
}

static char	*ft_ftoa_no_precision(double f, int len, int must_round_up)
{
	unsigned long long	nb;
	char				*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (must_round_up == 1)
		nb = (unsigned long long)f + ft_ftoa_round_up(f);
	else
		nb = (unsigned long long)f;
	while (0 < len)
	{
		str[--len] = ('0' + (nb % 10));
		nb /= 10;
	}
	return (str);
}

static char	*ft_ftoa_precision_fillstr(double f, int precision)
{
	unsigned long long	nb;
	char				*str;
	int					i;

	str = malloc(sizeof(char) * (precision + 2));
	if (!str)
		return (NULL);
	f = f - (unsigned long long)f;
	i = 0;
	while (i++ < precision)
		f *= 10;
	nb = (unsigned long long)f + ft_ftoa_round_up(f);
	str[precision + 1] = '\0';
	str[0] = '.';
	while (0 < precision)
	{
		str[precision--] = ('0' + (nb % 10));
		nb /= 10;
	}
	return (str);
}

static char	*ft_ftoa_precision(double f, int len, int precision)
{
	char	*tmp1;
	char	*tmp2;
	char	*str;

	tmp1 = ft_ftoa_no_precision(f, len, 0);
	if (!tmp1)
		return (NULL);
	tmp2 = ft_ftoa_precision_fillstr(f, precision);
	if (!tmp2)
	{
		free (tmp1);
		return (NULL);
	}
	str = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return (str);
}*/

/* gerer la precision line 119-120 : arrondir a ce moment, directement sur
	f pour eviter de nombreux bugs                                            */

/*char	*ft_nftoa(double f, int precision)
{
	int	len;

	if (f != f)
		return (ft_strdup ("nan"));
	if (f != 0 && (f < -DBL_MAX || (f > -DBL_MIN && f < DBL_MIN) \
		|| f > DBL_MAX))
		return (ft_strdup ("inf"));
	if (f < 0)
		f *= -1;
	len = ft_getlen_ull((unsigned long long)f, 10);
	if (precision == 0)
		return (ft_ftoa_no_precision(f, len, 1));
	return (ft_ftoa_precision(f, len, precision));
}*/

void	ft_ftoa_do_precision(double *f)
{
	int					i;
	int					resultfound;
	int					tmpnb;
	unsigned long long	nb;

	i = 0;
	resultfound = 0;
	while (resultfound == 0)
	{
		i += 1;
		nb = (unsigned long long)(*f);
		tmpnb = ((*f) * ft_powerten(i)) - (nb * ft_powerten(i));
		if (tmpnb > 5)
		{
			resultfound = 1;
			*f += 1;
		}
		if (tmpnb < 5)
			resultfound = 1;
	}
}

/*	if (tmpnb == 5) && ((unsigned long long)f) % 2 != 0 && \
		(unsigned long long)(f * ft_powerten(i)) - \
		((unsigned long long)f) * ft_powerten(i) == 0)
		f += 1;
		if no number after do round to even number. */

static char	*ft_nftoa_putinstr(double f, int len, int precision, char **str)
{
	int					i;
	unsigned long long	nb;

	i = 0;
	while (i++ < precision)
		f *= 10;
	ft_ftoa_do_precision(&f);
	nb = (unsigned long long)f;
	while (0 < precision)
	{
		(*str)[len + precision--] = ('0' + (nb % 10));
		nb /= 10;
	}
	while (0 < len)
	{
		(*str)[--len] = ('0' + (nb % 10));
		nb /= 10;
	}
	return (*str);
}

char	*ft_nftoa(double f, int precision)
{
	int		len;
	char	*str;

	if (f != f)
		return (ft_strdup ("nan"));
	if (f != 0 && (f < -DBL_MAX || (f > -DBL_MIN && f < DBL_MIN) \
		|| f > DBL_MAX))
		return (ft_strdup ("inf"));
	if (f < 0)
		f *= -1;
	len = ft_getlen_ull((unsigned long long)f, 10);
	str = malloc(sizeof(char) * (len + precision + 2));
	if (!str)
		return (NULL);
	str[len + precision + 1] = '\0';
	if (precision == 0)
		str[len] = '\0';
	else
		str[len] = '.';
	return (ft_nftoa_putinstr(f, len, precision, &str));
}
