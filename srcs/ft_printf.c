/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/14 13:35:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_update_from_arg(char **str, va_list *arg, int *i)
{
	int				j;
	t_value_printf	value_printf;

	if (ft_init_value_lst(&value_printf) != 0)
		return (-1);
	j = ft_parsing(*str, i, &value_printf, arg);
	free(value_printf.flags);
	free(value_printf.length);
	if (j == -1)
		return (-1);
	return (j);
}

static int	ft_get_results(char **str, va_list *arg, int *size)
{
	int		i;
	int		j;

	i = 0;
	while ((*str)[i] != '\0')
	{
		j = 0;
		while ((*str)[i + j] != '\0' && (*str)[i + j] != '%')
		{
			ft_putchar((*str)[i + j]);
			j++;
		}
		i = i + j;
		*size += j;
		if ((*str)[i] == '%')
		{
			i++;
			j = ft_update_from_arg(str, arg, &i);
			if (j < 0)
				return (-1);
			*size += j;
		}
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	char	*str;
	int		size;
	int		i;

	va_start(arg, input);
	if (input == NULL)
		return (-1);
	str = ft_strdup(input);
	size = 0;
	i = ft_get_results(&str, &arg, &size);
	free(str);
	va_end(arg);
	if (i == -1)
		return (-1);
	return (size);
}
