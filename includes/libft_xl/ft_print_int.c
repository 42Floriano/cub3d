/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:14:29 by albertini         #+#    #+#             */
/*   Updated: 2024/03/06 10:50:28 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(long nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		count += ft_print_char('-');
		count += ft_print_int(nb * -1);
	}
	else if (nb > 9)
	{
		count += ft_print_int(nb / 10);
		count += ft_print_int(nb % 10);
	}
	else if (nb < 10)
		count += ft_print_char(nb + 48);
	return (count);
}
