/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:03:55 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:18:09 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cdest;

	cdest = (char *)s;
	while (n)
	{
		if (*cdest == (char)c)
			return (cdest);
		cdest++;
		n--;
	}
	return (0);
}
