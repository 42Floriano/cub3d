/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:55:08 by albertini         #+#    #+#             */
/*   Updated: 2024/03/06 13:15:05 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lft	*ft_lstmap(t_lft *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lft	*new_list;
	t_lft	*save;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (0);
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (save);
}
