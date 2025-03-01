/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:32:40 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:18:43 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, unsigned int l)
{
	unsigned char	*t;

	t = str;
	while (l > 0)
	{
		*t = c;
		t++;
		l--;
	}
	return (str);
}
