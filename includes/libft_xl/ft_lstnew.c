/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:14:46 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:10:08 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lft	*ft_lstnew(void *content)
{
	t_lft	*new;

	new = (t_lft *)malloc(sizeof(t_lft));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
