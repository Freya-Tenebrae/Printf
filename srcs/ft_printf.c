/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/06 16:52:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_results(char ***strs)
{
	char	*result;
	int		numberofchar;

	result = ft_strdup("");
	numberofchar = ft_pars_printf(&result, strs);
	if (numberofchar > 0)
		return (-1);
	ft_putstr_fd(result, 1);
	return (numberofchar);
}

static int	ft_updatestrs(char ***strs, char *str, int position)
{
	(*strs)[position] = ft_strdup(str);
	if (!(*strs)[position])
	{
		while (--position >= 0)
			free((*strs)[position]);
		free(*strs);
		return (-1);
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		numberofargs;
	int		i;
	char	**strs;

	va_start(ap, input);
	numberofargs = 0;
	while (input != NULL)
		numberofargs++;
	if (numberofargs == 0)
		return (-1);
	strs = malloc(sizeof(char *) * (numberofargs + 1));
	if (!strs)
		return (-1);
	i = -1;
	while (++i <= numberofargs)
		if (ft_updatestrs(&strs, va_arg(ap, char *), i) != 0)
			return(-1);
	strs[numberofargs] = NULL;
	va_end(ap);
	return (ft_results(&strs));
}
