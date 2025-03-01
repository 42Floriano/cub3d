/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:28:23 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:10:43 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	size_t	l;

	l = ft_strlen(s);
	if (!d || !s)
		return (0);
	if (n > 0)
	{
		while (--n && (*s))
			*(d++) = *(s++);
		*d = '\0';
	}
	return (l);
}
