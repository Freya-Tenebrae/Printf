/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/01 16:09:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_update_from_arg(char **pstr, va_list *arg, int size)
{
	int				j;
	t_value_printf	value_printf;

	if (ft_init_value_lst(&value_printf) != 0)
		return (-1);
	j = ft_parsing(pstr, &value_printf, arg, size);
	free(value_printf.flags);
	free(value_printf.length);
	if (j == -1)
		return (-1);
	return (j);
}

static int	ft_get_results(char *str, va_list *arg, int *size)
{
	char	*pstr;
	int		i;

	pstr = str;
	if (!pstr)
		return (-1);
	while (*pstr != '\0')
	{
		i = 0;
		while (pstr[i] != '\0' && pstr[i] != '%')
		{
			ft_putchar(pstr[i]);
			*size += 1;
			pstr++;
		}
		if (*pstr == '%')
		{
			pstr++;
			i = ft_update_from_arg(&pstr, arg, *size);
			if (i < 0)
				return (-1);
			*size += i;
		}
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	char	*s;
	int		size;
	int		i;

	va_start(arg, input);
	if (input == NULL)
		return (-1);
	s = ft_strdup(input);
	size = 0;
	i = ft_get_results(s, &arg, &size);
	free(s);
	va_end(arg);
	if (i == -1)
		return (-1);
	return (size);
}
