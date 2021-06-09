/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:21:41 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/08 11:25:59 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
    printf("|test printf ()         :|\n");
    ft_printf("|test ft_printf ()      :|\n");
    ft_printf("|-------------------------\\\n");
    printf("|test printf (i)       :%i|\n", 42);
    ft_printf("|test ft_printf (i)    :%i|\n", 42);
    ft_printf("|-------------------------|\n");
    printf("|test printf (0i)      :%0i|\n", 42);
    ft_printf("|test ft_printf (0i)   :%0i|\n", 42);
    ft_printf("|--------------------------\\\n");
    printf("|test printf ( i)      :% i|\n", 42);
    ft_printf("|test ft_printf ( i)   :% i|\n", 42);
    ft_printf("|--------------------------|\n");
    printf("|test printf (+i)      :%+i|\n", 42);
    ft_printf("|test ft_printf (+i)   :%+i|\n", 42);
    ft_printf("|---------------------------\\\n");
    ft_printf("|----------------------------\\\n");
    printf("|test printf (5i)      :%5i|\n", 42);
    ft_printf("|test ft_printf (5i)   :%5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (05i)     :%05i|\n", 42);
    ft_printf("|test ft_printf (05i)  :%05i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (-5i)     :%-5i|\n", 42);
    ft_printf("|test ft_printf (-5i)  :%-5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( 5i)     :% 5i|\n", 42);
    ft_printf("|test ft_printf ( 5i)  :% 5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+5i)     :%+5i|\n", 42);
    ft_printf("|test ft_printf (+5i)  :%+5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( 05i)    :% 05i|\n", 42);
    ft_printf("|test ft_printf ( 05i) :% 05i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+05i)    :%+05i|\n", 42);
    ft_printf("|test ft_printf (+05i) :%+05i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( -5i)    :% -5i|\n", 42);
    ft_printf("|test ft_printf ( -5i) :% -5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+-5i)    :%+-5i|\n", 42);
    ft_printf("|test ft_printf (+-5i) :%+-5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (0 5i)    :%0 5i|\n", 42);
    ft_printf("|test ft_printf (0 5i) :%0 5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (0+5i)    :%0+5i|\n", 42);
    ft_printf("|test ft_printf (0+5i) :%0+5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (- 5i)    :%- 5i|\n", 42);
    ft_printf("|test ft_printf (- 5i) :%- 5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (-+5i)    :%-+5i|\n", 42);
    ft_printf("|test ft_printf (-+5i) :%-+5i|\n", 42);
    ft_printf("|----------------------------|\n");
}
