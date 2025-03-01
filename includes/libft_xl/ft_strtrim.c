/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:28:14 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:17:18 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Online solution that I liked very much 

static int	check(char const *str, char set)
{
	while (*str)
	{
		if (*str == set)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*cpy;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && (check(set, s1[start]) != 0))
		start++;
	if (start >= end)
		return (ft_strdup(""));
	while (end > start && (check(set, s1[end - 1]) != 0))
		end--;
	cpy = malloc((end - start + 1) * sizeof(char));
	if (!cpy)
		return (cpy);
	while (start < end)
		cpy[i++] = s1[start++];
	cpy[i] = '\0';
	return (cpy);
}
