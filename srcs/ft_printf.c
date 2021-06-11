/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/11 13:07:56 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_show_printf(char **result, char **str)
{
	int	len;

	ft_putstr_fd(*result, 1);
	len = ft_strlen(*result);
	ft_freeprintf(result, str);
	return (len);
}

static int	ft_update_from_arg(char **result, char **str, va_list *arg, int *i)
{
	int				j;
	t_value_printf	value_printf;
	char			*portion_to_add;
	char			*tmp;

	(void)arg;
	if (ft_init_value_lst(&value_printf) != 0)
		return (-1);
	j = ft_parsing(*str, *i, &value_printf, arg);
	if (j < 0)
	{
		ft_freeprintf(result, str);
		return (-1);
	}
	*i = *i + j;
	portion_to_add = ft_get_value(&value_printf);
	if (portion_to_add == NULL)
		ft_freeprintf(result, str);
	tmp = ft_strjoin(*result, portion_to_add);
	free(portion_to_add);
	if (tmp == NULL)
		ft_freeprintf(result, str);
	free(*result);
	*result = tmp;
	return (0);
}

static int	ft_update_from_str(char **result, char **str, int i, int j)
{
	char	*resultpart;
	char	*tmp;

	if (j == 0)
		return (0);
	tmp = *str;
	while (i-- > 0)
		tmp++;
	resultpart = ft_strndup(tmp, j);
	if (!resultpart)
		ft_freeprintf(result, str);
	tmp = ft_strjoin(*result, resultpart);
	free(resultpart);
	if (!tmp)
	{
		free(*str);
		return (-1);
	}
	free(*result);
	*result = tmp;
	return (0);
}

static int	ft_get_results(char **str, va_list *arg)
{
	char	*result;
	int		i;
	int		j;

	result = ft_strdup("");
	i = 0;
	while ((*str)[i] != '\0')
	{
		j = 0;
		while ((*str)[i + j] != '\0' && (*str)[i + j] != '%')
			j++;
		if (ft_update_from_str(&result, str, i, j) != 0)
			return (-1);
		i = i + j;
		if ((*str)[i] == '%')
		{
			i++;
			if (ft_update_from_arg(&result, str, arg, &i) != 0)
				return (-1);
		}
	}
	return (ft_show_printf(&result, str));
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	char	*str;
	int		size;

	va_start(arg, input);
	if (input == NULL)
		return (-1);
	str = ft_strdup(input);
	size = ft_get_results(&str, &arg);
	va_end(arg);
	return (size);
}
