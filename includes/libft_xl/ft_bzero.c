/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:16:16 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 13:14:07 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, unsigned int l)
{
	unsigned char	*t;

	t = str;
	while (l > 0)
	{
		*t = '\0';
		t++;
		l--;
	}
	return (t);
}
