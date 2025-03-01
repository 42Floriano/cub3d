/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:41:44 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:13:25 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lft	*ft_lstlast(t_lft *lst)
{
	t_lft	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
