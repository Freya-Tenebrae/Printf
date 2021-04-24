/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:27:03 by cmaginot          #+#    #+#             */
/*   Updated: 2021/04/19 17:03:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbstr(char const *s, char c)
{
	int number;
	int i;

	number = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			number++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (number);
}

static char		**ft_splitting(char **strs, char const *s, char c, int strs_l)
{
	int		i;
	int		j;

	i = 0;
	while (i < strs_l)
	{
		while (*s != '\0' && *s == c)
			s++;
		j = 0;
		while (s[j] != '\0' && s[j] != c)
			j++;
		if (!(strs[i] = (char *)malloc(j + 1)))
			return (0);
		j = 0;
		while (*s != '\0' && *s != c)
			strs[i][j++] = *s++;
		strs[i++][j] = 0;
	}
	strs[i] = 0;
	return (strs);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	int		strs_l;

	if (s == 0)
		return (0);
	strs_l = ft_nbstr(s, c);
	if (!(strs = (char **)malloc((strs_l + 1) * sizeof(char *))))
		return (0);
	return (ft_splitting(strs, s, c, strs_l));
}
