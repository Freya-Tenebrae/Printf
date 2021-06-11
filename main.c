/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:21:41 by cmaginot          #+#    #+#             */
/*   Updated: 2021/06/11 15:59:11 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
    printf("|test printf ()        :|\n");
    ft_printf("|test ft_printf ()     :|\n");
    ft_printf("|------------------------\\\n");
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
    ft_printf("|-----------------------------\\___\n");
    printf("|test printf (-+*i)    :%-+*i|\n", 10, 42);
    ft_printf("|test ft_printf (-+*i) :%-+*i|\n", 10, 42);
    ft_printf("|---------------------------------|\n");
    printf("|test printf (+*i)     :%+*i|\n", 10, 42);
    ft_printf("|test ft_printf (+*i)  :%+*i|\n", 10, 42);
    ft_printf("|---------------------------------|\n");
    printf("|test printf (0+*i)    :%0+*i|\n", 10, 42);
    ft_printf("|test ft_printf (0+*i) :%0+*i|\n", 10, 42);
    ft_printf("|---------------------------------|\n");

    printf("|test printf (.5i)       :%.5i|\n", 42);
    ft_printf("|test ft_printf (.5i)    :%.5i|\n", 42);
    ft_printf("|-------------------------|\n");
    printf("|test printf (0.5i)      :%0.5i|\n", 42);
    ft_printf("|test ft_printf (0.5i)   :%0.5i|\n", 42);
    ft_printf("|--------------------------\\\n");
    printf("|test printf ( .5i)      :% .5i|\n", 42);
    ft_printf("|test ft_printf ( .5i)   :% .5i|\n", 42);
    ft_printf("|--------------------------|\n");
    printf("|test printf (+.5i)      :%+.5i|\n", 42);
    ft_printf("|test ft_printf (+.5i)   :%+.5i|\n", 42);
    ft_printf("|---------------------------\\\n");
    printf("|test printf (5.5i)      :%5.5i|\n", 42);
    ft_printf("|test ft_printf (5.5i)   :%5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (05.5i)     :%05.5i|\n", 42);
    ft_printf("|test ft_printf (05.5i)  :%05.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (-5.5i)     :%-5.5i|\n", 42);
    ft_printf("|test ft_printf (-5.5i)  :%-5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( 5.5i)     :% 5.5i|\n", 42);
    ft_printf("|test ft_printf ( 5.5i)  :% 5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+5.5i)     :%+5.5i|\n", 42);
    ft_printf("|test ft_printf (+5.5i)  :%+5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( 05.5i)    :% 05.5i|\n", 42);
    ft_printf("|test ft_printf ( 05.5i) :% 05.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+05.5i)    :%+05.5i|\n", 42);
    ft_printf("|test ft_printf (+05.5i) :%+05.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( -5.5i)    :% -5.5i|\n", 42);
    ft_printf("|test ft_printf ( -5.5i) :% -5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+-5.5i)    :%+-5.5i|\n", 42);
    ft_printf("|test ft_printf (+-5.5i) :%+-5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (0 5.5i)    :%0 5.5i|\n", 42);
    ft_printf("|test ft_printf (0 5.5i) :%0 5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (0+5.5i)    :%0+5.5i|\n", 42);
    ft_printf("|test ft_printf (0+5.5i) :%0+5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (- 5.5i)    :%- 5.5i|\n", 42);
    ft_printf("|test ft_printf (- 5.5i) :%- 5.5i|\n", 42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (-+5.5i)    :%-+5.5i|\n", 42);
    ft_printf("|test ft_printf (-+5.5i) :%-+5.5i|\n", 42);
    ft_printf("|-----------------------------\\___\n");
    printf("|test printf (-+*.5i)    :%-+*.5i|\n", 10, 42);
    ft_printf("|test ft_printf (-+*.5i) :%-+*.5i|\n", 10, 42);
    ft_printf("|---------------------------------|\n");
    printf("|test printf (+*.*i)     :%+*.*i|\n", 10, 5, 42);
    ft_printf("|test ft_printf (+*.*i)  :%+*.*i|\n", 10, 5, 42);
    ft_printf("|---------------------------------|\n");
    printf("|test printf (0+*,*i)    :%0+*.*i|\n", 10, 5, 42);
    ft_printf("|test ft_printf (0+*.*i) :%0+*.*i|\n", 10, 5, 42);
    ft_printf("|---------------------------------|\n");
    
    ft_printf("\n");
    ft_printf("\n");
    ft_printf("\n");
    
    printf("|test printf ()        :|\n");
    ft_printf("|test ft_printf ()     :|\n");
    ft_printf("|------------------------\\_\n");
    printf("|test printf (i)       :%i|\n", -42);
    ft_printf("|test ft_printf (i)    :%i|\n", -42);
    ft_printf("|--------------------------|\n");
    printf("|test printf (0i)      :%0i|\n", -42);
    ft_printf("|test ft_printf (0i)   :%0i|\n", -42);
    ft_printf("|--------------------------|\n");
    printf("|test printf ( i)      :% i|\n", -42);
    ft_printf("|test ft_printf ( i)   :% i|\n", -42);
    ft_printf("|--------------------------|\n");
    printf("|test printf (+i)      :%+i|\n", -42);
    ft_printf("|test ft_printf (+i)   :%+i|\n", -42);
    ft_printf("|---------------------------\\\n");
    printf("|test printf (5i)      :%5i|\n", -42);
    ft_printf("|test ft_printf (5i)   :%5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (05i)     :%05i|\n", -42);
    ft_printf("|test ft_printf (05i)  :%05i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (-5i)     :%-5i|\n", -42);
    ft_printf("|test ft_printf (-5i)  :%-5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( 5i)     :% 5i|\n", -42);
    ft_printf("|test ft_printf ( 5i)  :% 5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+5i)     :%+5i|\n", -42);
    ft_printf("|test ft_printf (+5i)  :%+5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( 05i)    :% 05i|\n", -42);
    ft_printf("|test ft_printf ( 05i) :% 05i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+05i)    :%+05i|\n", -42);
    ft_printf("|test ft_printf (+05i) :%+05i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf ( -5i)    :% -5i|\n", -42);
    ft_printf("|test ft_printf ( -5i) :% -5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (+-5i)    :%+-5i|\n", -42);
    ft_printf("|test ft_printf (+-5i) :%+-5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (0 5i)    :%0 5i|\n", -42);
    ft_printf("|test ft_printf (0 5i) :%0 5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (0+5i)    :%0+5i|\n", -42);
    ft_printf("|test ft_printf (0+5i) :%0+5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (- 5i)    :%- 5i|\n", -42);
    ft_printf("|test ft_printf (- 5i) :%- 5i|\n", -42);
    ft_printf("|----------------------------|\n");
    printf("|test printf (-+5i)    :%-+5i|\n", -42);
    ft_printf("|test ft_printf (-+5i) :%-+5i|\n", -42);
    ft_printf("|-----------------------------\\___\n");
    printf("|test printf (-+*i)    :%-+*i|\n", 10, -42);
    ft_printf("|test ft_printf (-+*i) :%-+*i|\n", 10, -42);
    ft_printf("|---------------------------------|\n");
    printf("|test printf (+*i)     :%+*i|\n", 10, -42);
    ft_printf("|test ft_printf (+*i)  :%+*i|\n", 10, -42);
    ft_printf("|---------------------------------|\n");
    printf("|test printf (0+*i)    :%0+*i|\n", 10, -42);
    ft_printf("|test ft_printf (0+*i) :%0+*i|\n", 10, -42);
    ft_printf("|---------------------------------|\n");
    
    ft_printf("\n");
    ft_printf("\n");
    ft_printf("\n");
    
    printf("|test printf ()        :|\n");
    ft_printf("|test ft_printf ()     :|\n");
    ft_printf("|------------------------\\\n");
    printf("|test printf (c)       :%c|\n", 'c');
    ft_printf("|test ft_printf (c)    :%c|\n", 'c');
    ft_printf("|---------------------------\\\n");
    printf("|test printf (5c)      :%5c|\n", 'c');
    ft_printf("|test ft_printf (5c)   :%5c|\n", 'c');
    ft_printf("|----------------------------|\n");
    printf("|test printf (-5c)     :%-5c|\n", 'c');
    ft_printf("|test ft_printf (-5c)  :%-5c|\n", 'c');
    ft_printf("|-----------------------------\\___\n");
    printf("|test printf (-*c)     :%-*c|\n", 10, 'c');
    ft_printf("|test ft_printf (-*c)  :%-*c|\n", 10, 'c');
    ft_printf("|---------------------------------|\n");
    printf("|test printf (*c)      :%*c|\n", 10, 'c');
    ft_printf("|test ft_printf (*c)   :%*c|\n", 10, 'c');
    ft_printf("|---------------------------------|\n");
    
    ft_printf("\n");
    ft_printf("\n");
    ft_printf("\n");
    
    printf("|test printf ()        :|\n");
    ft_printf("|test ft_printf ()     :|\n");
    ft_printf("|------------------------\\____\n");
    printf("|test printf (s)       :%s|\n", "coucou");
    ft_printf("|test ft_printf (s)    :%s|\n", "coucou");
    ft_printf("|-----------------------------\\____\n");
    printf("|test printf (10s)      :%10s|\n", "coucou");
    ft_printf("|test ft_printf (10s)   :%10s|\n", "coucou");
    ft_printf("|----------------------------------|\n");
    printf("|test printf (-10s)     :%-10s|\n", "coucou");
    ft_printf("|test ft_printf (-10s)  :%-10s|\n", "coucou");
    ft_printf("|----------------------------------\\________\n");
    printf("|test printf (-*s)     :%-*s|\n", 20, "coucou");
    ft_printf("|test ft_printf (-*s)  :%-*s|\n", 20, "coucou");
    ft_printf("|-------------------------------------------|\n");
    printf("|test printf (*s)      :%*s|\n", 20, "coucou");
    ft_printf("|test ft_printf (*s)   :%*s|\n", 20, "coucou");
    ft_printf("|-------------------------------------------|\n");

    ft_printf("\n");
    ft_printf("\n");
    ft_printf("\n");
    
    // printf("|test printf ()           :%-c%-c%c*|\n", 1, '0', 0); //c 21
    // ft_printf("|test ft_printf ()        :%-c%-c%c*|\n", 1, '0', 0);

    // printf("|test printf ()           :%c|\n", 0); //c 24
    // ft_printf("|test ft_printf ()        :%c|\n", 0);
    // printf("|test printf ()           :0%c|\n", 0); //c 25
    // ft_printf("|test ft_printf ()        :0%c|\n", 0);
    printf("|test printf ()           :-%*s*|\n", 5, "\0");
    ft_printf("|test ft_printf ()        :-%*s*|\n", 5, "\0");
    printf("|test printf ()           :-%*c*|\n", 5, '\0');
    ft_printf("|test ft_printf ()        :-%*c*|\n", 5, '\0');
    // printf("|test printf ()           : -%*c* -%-*c* |\n", -2, 0, 2, 0);
    // ft_printf("|test ft_printf ()        : -%*c* -%-*c* |\n", -2, 0, 2, 0);
    // printf("|test printf ()           : -%-*c* -%-*c* |\n", 2, 0, -2, 0);
    // ft_printf("|test ft_printf ()        : -%-*c* -%-*c* |\n", 2, 0, -2, 0);
    // printf("|test printf ()           : -%*c* -%-*c* |\n", -1, 0, 1, 0);
    // ft_printf("|test ft_printf ()        : -%*c* -%-*c* |\n", -1, 0, 1, 0);
    // printf("|test printf ()           : -%-*c* -%-*c* |\n", 2, 0, -2, 0);
    // ft_printf("|test ft_printf ()        : -%-*c* -%-*c* |\n", 2, 0, -2, 0);
    // printf("|test printf ()           : -%-2c* -%2c* |\n", 0, 0);
    // ft_printf("|test ft_printf ()        : -%-2c* -%2c* |\n", 0, 0);
}
