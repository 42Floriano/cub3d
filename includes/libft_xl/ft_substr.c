/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:52:34 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:19:52 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;
	unsigned int		j;
	unsigned int		strlen;

	new = (char *)malloc(((size_t)len + 1) * sizeof(char));
	if (!new)
		return (new);
	i = start;
	j = 0;
	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		new[0] = '\0';
		return (new);
	}
	while (s[i] && len)
	{
		new[j] = s[i];
		j++;
		i++;
		len--;
	}
	new[j] = '\0';
	return (new);
}
