#include "../includes/ft_printf.h"

static int  ft_printf_cw_conditionning_2(t_value_printf *value_printf, char *c, char ***value)
{
    int    l;

    l = ft_printf_conditionning_width(value_printf, 1, &(*value)[0], &(*value)[1]);
    if (l >= 0)
    {
        ft_putstr((*value)[0]);
        ft_putwchar(*c);
        ft_putstr((*value)[1]);
    }
    return (l);
}

static int  ft_printf_c_conditionning_2(t_value_printf *value_printf, char *c, char ***value)
{
    int    l;

    l = ft_printf_conditionning_width(value_printf, 1, &(*value)[0], &(*value)[1]);
    if (l < 0)
        return (l);
    ft_putstr((*value)[0]);
    ft_putchar(*c);
    ft_putstr((*value)[1]);
    return (l);
}

int    ft_printf_cw_conditionning_1(t_value_printf *value_printf, \
    char c)
{
    char    **value;
    int     l;

    value = malloc(sizeof(char **) * 2);
    if (!value)
        return (-1);
    value[0] = ft_strdup("");
    if (!value[0])
    {
        free(value);
        return (-1);
    }
    value[1] = ft_strdup("");
    if (!value[1])
    {
        free(value[0]);
        free(value);
        return (-1);
    }
    l = ft_printf_cw_conditionning_2(value_printf, &c, &value);
    free(value[0]);
    free(value[1]);
    free(value);
    return (l);
}

int    ft_printf_c_conditionning_1(t_value_printf *value_printf, \
    char c)
{
    char    **value;
    int     l;

    value = malloc(sizeof(char **) * 2);
    if (!value)
        return (-1);
    value[0] = ft_strdup("");
    if (!value[0])
    {
        free(value);
        return (-1);
    }
    value[1] = ft_strdup("");
    if (!value[1])
    {
        free(value[0]);
        free(value);
        return (-1);
    }
    l = ft_printf_c_conditionning_2(value_printf, &c, &value);
    free(value[0]);
    free(value[1]);
    free(value);
    return (l);
}
