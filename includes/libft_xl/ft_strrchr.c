/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:08:35 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:17:48 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	*str;

	str = (char *)s;
	l = ft_strlen(str);
	while (l >= 0)
	{
		if (str[l] == (unsigned char)c)
			return (&str[l]);
		l--;
	}
	return (0);
}
