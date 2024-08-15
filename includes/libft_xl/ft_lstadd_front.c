/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:32:10 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:15:37 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//modifie l'adresse de la tête de liste par la nouvelle tete de liste 
void	ft_lstadd_front(t_lft **lst, t_lft *new)
{
	new->next = *lst;
	*lst = new;
}
