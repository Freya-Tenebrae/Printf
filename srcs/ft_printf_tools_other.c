/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_other.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:32:59 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:10:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char	*ft_straddcharendstr(const char *s, char const c)
{
	char			*res;
	size_t			len;
	unsigned int	i;

	if (s == NULL)
		return (0);
	len = ft_strlen(s) + 2;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	ft_bzero(res, len);
	i = -1;
	while (s[++i] != '\0')
		res[i] = s[i];
	res[i++] = c;
	res[i] = '\0';
	return (res);
}

char	*ft_straddcharstartstr(const char *s, char const c)
{
	char			*res;
	size_t			len;
	unsigned int	i;

	if (s == NULL)
		return (0);
	len = ft_strlen(s) + 2;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	ft_bzero(res, len);
	i = 0;
	res[i] = c;
	while (s[++i - 1] != '\0')
		res[i] = s[i - 1];
	res[i] = '\0';
	return (res);
}

wchar_t	*ft_wstrndup(const wchar_t *ws1, size_t n)
{
	wchar_t	*wstr;
	size_t	i;

	wstr = malloc((n + 1) * sizeof(wchar_t));
	if (!wstr)
		return (0);
	i = -1;
	while (++i < n)
		wstr[i] = ws1[i];
	wstr[i] = '\0';
	return (wstr);
}

wchar_t	*ft_wstrdup(const wchar_t *ws1)
{
	return (ft_wstrndup(ws1, ft_wstrlen(ws1)));
}
