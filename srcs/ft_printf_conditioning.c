/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conditioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:07:14 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/16 12:13:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
TODO :
        -do lenght
        -do ft_get_value properly
        -do other specifier, make fonction for them and not atoi or other ...
        exeption : ajouter +1 au score final lorsque l'on utilise un char '/0' 
        pour c
*/

/* char	*ft_get_value(t_value_printf *value_printf, char *content)
{
	char	*result;
	char	*tmp1;
	char	*tmp2;
	int		char_to_add;
	int		i;

	result = ft_strdup(content);
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
		if (result[0] == '\0' && value_printf->specifier == 'c')
			char_to_add--;
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
	return (result);
} */
