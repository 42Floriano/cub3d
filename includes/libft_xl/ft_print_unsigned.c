/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:15:35 by albertini         #+#    #+#             */
/*   Updated: 2024/03/06 12:37:21 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count = ft_print_unsigned(nb / 10);
		return (count + ft_print_unsigned(nb % 10));
	}
	else if (nb < 10)
		count += ft_print_char(nb + 48);
	return (count);
}
