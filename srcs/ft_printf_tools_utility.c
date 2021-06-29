/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_utility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:34:50 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/29 09:34:00 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_init_value_lst(t_value_printf *value_printf)
{
	value_printf->flags = ft_strdup("");
	if (!value_printf->flags)
		return (-1);
	value_printf->width = 0;
	value_printf->is_precision = 0;
	value_printf->precision = 0;
	value_printf->length = NULL;
	value_printf->specifier = '\0';
	return (0);
}

int	ft_init_value_conditionning(char ***value)
{
	(*value) = malloc(sizeof(char **) * 3);
	if (!(*value))
		return (-1);
	(*value)[2] = NULL;
	(*value)[0] = ft_strdup("");
	if (!(*value)[0])
	{
		ft_free_value_conditionning(value);
		return (-1);
	}
	(*value)[1] = ft_strdup("");
	if (!(*value)[1])
	{
		ft_free_value_conditionning(value);
		return (-1);
	}
	return (0);
}

void	ft_free_value_conditionning(char ***value)
{
	int	i;

	i = -1;
	while ((*value)[++i] != NULL)
		free((*value)[i]);
	free((*value));
}

int	ft_powerten(int i)
{
	int pow;

	pow = 1;
	while (i-- < 0)
		pow *= 10;
	return (pow);
}
