/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 00:34:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/08 11:47:45 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// refaire tout depuis le parsing : IL NE FAUT PAS GERER LES FORMES INDETERMINEE

static int  ft_freeprintf(char **result, char **str)
{
    free(*result);
    free(*str);
    return (-1);
}

static char *ft_flag_translation_part1(char *flags, char *result)
{
    int     i;
    int     plus_present;
    char    *tmp;
    
    i = 0;
    plus_present = 0;
    if (flags[i] == '+' || flags[i] == ' ')
    {
        if (result[0] != '-')
        {
            if (flags[i] == '+')
                tmp = ft_strjoin("+", result);
            else
                tmp = ft_strjoin(" ", result);
            if (!tmp)
                return (NULL);
            free (result);
            result = tmp;
        }
        plus_present++;
        i++;
    }
    if ()
    return (result);
}

//static char *ft_flag_translation_part2(char *flags, char *result)
//{
//
//}

static char *ft_print_spec_i(char *flags, int i)
{
    char    *result;
    
    result = ft_itoa(i);
    return (ft_flag_translation_part1(flags, result));
}

static char ft_getspecifier(char *flags)
{
    int     i;
    
    i = 0;
    while (flags[i] != '\0')
        i++;
    i--;
    return (flags[i]);
}

static char *ft_flags_interpretation(char *flags, va_list *arg)
{
    char    specifier;
    
    specifier = ft_getspecifier(flags);
//    if (specifier == 'c')
//        return (ft_print_spec_c(flags, va_arg(*arg, char)));
//    else if (specifier == 's')
//        return (ft_print_spec_s(flags, va_arg(*arg, char *)));
//    else if (specifier == 'p')
//        return (ft_print_spec_p(flags, va_arg(*arg, /* need */)));
//    else if (specifier == 'd')
//        return (ft_print_spec_d(flags, va_arg(*arg, /* need */)));
/*    else*/ if (specifier == 'i')
        return (ft_print_spec_i(flags, va_arg(*arg, int)));
//    else if (specifier == 'u')
//        return (ft_print_spec_u(flags, va_arg(*arg, /* need */)));
//    else if (specifier == 'e')
//        return (ft_print_spec_e(flags, va_arg(*arg, /* need */)));
//    else if (specifier == 'n')
//        return (ft_print_spec_n(flags, va_arg(*arg, /* need */)));
//    else if (specifier == 'f')
//        return (ft_print_spec_f(flags, va_arg(*arg, /* need */)));
//    else if (specifier == 'g')
//        return (ft_print_spec_g(flags, va_arg(*arg, /* need */)));
//    else if (specifier == 'x')
//        return (ft_print_spec_x(flags, va_arg(*arg, /* need */)));
//    else if (specifier == 'X')
//        return (ft_print_spec_X(flags, va_arg(*arg, /* need */)));
//    else if (specifier == '%')
//        return (ft_print_spec_%(flags, va_arg(*arg, /* need */)));
    return(NULL);
}

static int  ft_getflags(char *str, int i, char **flags)
{
    int     j;
    int     plus_present;
    
    j = 0;
    plus_present = 0;
    if (str[i + j] == '+' || str[i + j] == ' ')
    {
        plus_present++;
        j++;
    }
    if (str[i + j] == '-' || str[i + j] == '0')
        j++;
    if (str[i + j] == '+' || str[i + j] == ' ')
    {
        if (plus_present != 0)
            return(-1);
        j++;
    }
    if (str[i + j] == '*')
        j++;
    else
        while (ft_isdigit(str[i + j]) == 1)
            j++;
    if (str[i + j] == '.')
    {
        j++;
        if (str[i + j] == '*')
            j++;
        else
            while (ft_isdigit(str[i + j]) == 1)
                j++;
    }
    j++;
    *flags = ft_strndup(&(str)[i], j);
    return(j);
}

static int  ft_parsing(char **result, char **str, va_list *arg, int *i)
{
    int     j;
    char    *flags;
    char    *portion_to_add;
    char    *tmp;

    (void)arg;

    j = ft_getflags(*str, *i, &flags);
    if (j < 0)
    {
        ft_freeprintf(result, str);
        return (-1);
    }
    *i = *i + j;
    portion_to_add = ft_flags_interpretation(flags, arg);
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

	(void)arg;

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
			if (ft_parsing(&result, str, arg, &i) != 0)
				return (-1);
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
