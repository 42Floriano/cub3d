/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:32:44 by falberti          #+#    #+#             */
/*   Updated: 2024/09/17 11:40:50 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strr;
	int		size;
	int		i;

	size = ft_strlen(s1);
	strr = malloc((size + 1) * sizeof(char));
	if (!strr)
		return (strr);
	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strr[i] = s1[i];
		i++;
	}
	strr[i] = '\0';
	return (strr);
}
