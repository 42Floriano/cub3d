/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:49:41 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:16:58 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char			*cdest;
	char			*csrc;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	if (cdest < csrc)
	{
		while (n--)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	return (dest);
}
