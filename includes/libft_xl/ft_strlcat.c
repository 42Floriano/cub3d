/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:30:28 by falberti          #+#    #+#             */
/*   Updated: 2023/10/27 13:48:31 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;

	dlen = ft_strlen(d);
	slen = ft_strlen(s);
	if (n < dlen)
		return (slen + n);
	i = 0;
	while ((dlen + 1) < n && s[i])
		d[dlen++] = s[i++];
	d[dlen] = '\0';
	return (ft_strlen(d) + ft_strlen(&s[i]));
}
