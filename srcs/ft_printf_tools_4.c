#include "../includes/ft_printf.h"

static unsigned long long	ft_ftoa_round_up(double f)
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
}

char	*ft_nftoa(double f, int precision)
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
}
