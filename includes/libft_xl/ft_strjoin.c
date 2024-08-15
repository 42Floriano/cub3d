/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:37 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 12:58:29 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*new;
	unsigned int		i;
	int					len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (new);
	i = 0;
	while (*s1)
		new[i++] = *(s1++);
	while (*s2)
		new[i++] = *(s2++);
	new[i] = '\0';
	return (new);
}
