/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:21:41 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/06 16:47:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static void	ft_free_strs(char ***strs)
// {
// 	int	i;

// 	i = 0;
// 	while ((*strs)[i] != NULL)
// 		free((*strs)[i++]);
// 	free(*strs);
// 	*strs = NULL;
// }

// static int	ft_updateoutput(char **result, char ***strs, int i, int j)
// {
// 	char	*resultpart;
// 	char	*tmp;

// 	if (j == 0)
// 		return (0);
// 	tmp = (*strs)[0];
// 	while (i-- >= 0)
// 		tmp++;
// 	resultpart = ft_strndup(tmp, j);
// 	if (!resultpart)
// 	{
// 		free(*result);
// 		ft_free_strs(strs);
// 		return (-1);
// 	}
// 	tmp = ft_strjoin(*result, resultpart);
// 	free(*result);
// 	free(resultpart);
// 	*result = tmp;
// 	if (!*result)
// 	{
// 		ft_free_strs(strs);
// 		return (-1);
// 	}
// 	return (0);
// }

int	ft_pars_printf(char **result, char ***strs)
{
	int		i;
	//int		j;
	(void)result;

	i = 0;
	while ((*strs)[0][i] != '\0')
	{
		// j = 0;
		// while ((*strs)[0][i + j] != '\0' && (*strs)[0][i + j] != '%' && \
		// 	(*strs)[0][i + j] != '\\')
		// 	j++;
		// if (ft_updateoutput(result, strs, i, j) != 0)
		// 	return (-1);
		// i = j;
		// if ((*strs)[0][i] != '\0')
		// {
			i++;
			//fonction to used flags and update i
		// }
	}
	return (i);
}