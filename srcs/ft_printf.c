/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/08 11:25:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int  ft_freeprintf(char **result, char **str)
{
    free(*result);
    free(*str);
    return (-1);
}

// static char *ft_flag_interpretation(char *flag, va_list *ap)
// {
//     (void)flag;
//     (void)ap;
//     return(NULL);
// }

// static int  ft_getflags(char *str, int i, char **flag)
// {
//     int     j;
//     char    *c_conversion;

//     j = 0;
//     c_conversion = NULL;
//     while (c_conversion == NULL)
//     {
//         // check is the flag are valid;
//         j++;
//         c_conversion = ft_strchr("cspdiuxnfgeX%", str[i + j]);
//     }
//     *flag = ft_strndup(&(str)[i], j); // check priority for &
//     j++;
//     return(j);
// }

// static int  ft_parsing(char **result, char **str, va_list *ap, int *i)
// {
//     int     j;
//     char    *flag;
//     char    *portion_to_add;
//     char    *tmp;

//     j = ft_getflags(*str, *i, &flag);
//     if (j < 0)
//         ft_freeprintf(result, str);
//     i = i + j;
//     portion_to_add = ft_flag_interpretation(flag, ap);
//     if (portion_to_add == NULL)
//         ft_freeprintf(result, str);
//     tmp = ft_strjoin(*result, portion_to_add);
//     free(portion_to_add);
//     if (tmp == NULL)
//         ft_freeprintf(result, str);
//     free(*result);
//     *result = tmp;
//     return (0);
// }

static int  ft_updateoutput(char **result, char **str, int i, int j)
{
    char    *resultpart;
    char    *tmp;

    if (j == 0)
        return (0);
    tmp = *str;
    while (i-- > 0)
        tmp++;
    resultpart = ft_strndup(tmp, j);
    if (!resultpart)
        ft_freeprintf(result, str);
    tmp = ft_strjoin(*result, resultpart);
    free(*result);
    free(resultpart);
    *result = tmp;
    if (!*result)
    {
        free(*str);
        return (-1);
    }
    return (0);
}

static int	ft_get_results(char **str, va_list *ap)
{
	char	*result;
	int		i;
	int		j;

	(void)ap;

	result = ft_strdup("");
	i = 0;
	while ((*str)[i] != '\0')
	{
		j = 0;
		while ((*str)[i + j] != '\0' && (*str)[i + j] != '%')
			j++;
		if (ft_updateoutput(&result, str, i, j) != 0)
			return (-1);
		i = i + j;
		if ((*str)[i] == '%')
		{
			i++;
			//if (ft_parsing(&result, str, ap, &i) != 0)
			//	return (-1);
		}
	}
	ft_putstr_fd(result, 1);
	return (i);
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
