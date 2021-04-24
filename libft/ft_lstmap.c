/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 02:15:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/04/24 17:41:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *newelem;

	(void)del;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	if (!(newelem = ft_lstnew(f(lst->content))))
		return (0);
	newlst = newelem;
	lst = lst->next;
	while (lst != 0)
	{
		if (!(newelem = ft_lstnew(f(lst->content))))
			return (0);
		ft_lstadd_back(&newlst, newelem);
		lst = lst->next;
	}
	return (newlst);
}
