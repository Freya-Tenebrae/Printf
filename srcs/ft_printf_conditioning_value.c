/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conditioning_value.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:07:14 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/11 15:07:50 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
TODO :
        -do precision before width
        -do lenght
        -do ft_get_value properly
        -do other specifier, make fonction for them and not atoi or other ...
*/

char	*ft_get_value(t_value_printf *value_printf)
{
	char	*result;
	char	*tmp1;
	char	*tmp2;
	int		char_to_add;
	int		i;

	result = ft_strdup(value_printf->content);
	if (value_printf->precision != 0 && \
		ft_strchr("diefgo", value_printf->specifier) != NULL)
	{
		char_to_add = value_printf->precision - ft_strlen(result);
		if (char_to_add > 0)
		{
			tmp1 = malloc(sizeof(char) * (char_to_add + 1));
			if (!tmp1)
			{
				free(result);
				return (NULL);
			}
			i = 0;
			while (i < char_to_add)
			{
				if (result[0] == '-' && i == 0 && \
					ft_strchr("diefgo", value_printf->specifier) != NULL)
				{
					tmp1[i++] = result[0];
					result[0] = '0';
				}
				else
					tmp1[i++] = '0';
			}
			tmp1[i] = '\0';
			tmp2 = ft_strjoin(tmp1, result);
			free(tmp1);
			free(result);
			if (!tmp2)
				return (NULL);
			result = tmp2;
		}
	}
	if ((ft_strchr(value_printf->flags, '+') != NULL || \
			ft_strchr(value_printf->flags, ' ') != NULL) && \
			result[0] != '-' && ft_strchr("diefgo", value_printf->specifier) \
			!= NULL)
	{
		if (ft_strchr(value_printf->flags, '+') != NULL)
			tmp1 = ft_strjoin("+", result);
		else
			tmp1 = ft_strjoin(" ", result);
		free(result);
		if (!tmp1)
			return (NULL);
		result = tmp1;
	}
	if (value_printf->width != 0)
	{
		char_to_add = value_printf->width - ft_strlen(result);
		if (char_to_add > 0)
		{
			tmp1 = malloc(sizeof(char) * (char_to_add + 1));
			if (!tmp1)
			{
				free(result);
				return (NULL);
			}
			i = 0;
			while (i < char_to_add)
			{
				if (ft_strchr(value_printf->flags, '0') != NULL && \
					(ft_strchr(value_printf->flags, '-') == NULL && \
					value_printf->precision == 0))
				{
					if ((result[0] == '-' || result[0] == ' ' || \
						result[0] == '+' ) && i == 0 && \
						ft_strchr("diefgo", value_printf->specifier) != NULL)
					{
						tmp1[i++] = result[0];
						result[0] = '0';
					}
					else
						tmp1[i++] = '0';
				}
				else
					tmp1[i++] = ' ';
			}
			tmp1[i] = '\0';
			if (ft_strchr(value_printf->flags, '-') == NULL)
				tmp2 = ft_strjoin(tmp1, result);
			else
				tmp2 = ft_strjoin(result, tmp1);
			free(tmp1);
			free(result);
			if (!tmp2)
				return (NULL);
			result = tmp2;
		}
	}
	value_printf->width = 0;
	value_printf->precision = 0;
	value_printf->specifier = '\0';
	free(value_printf->flags);
	free(value_printf->length);
	free(value_printf->content);
	return (result);
}
