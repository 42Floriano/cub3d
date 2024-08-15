/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_classic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:09:45 by albertini         #+#    #+#             */
/*   Updated: 2024/03/06 10:50:44 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			count += ft_print_char(str[count]);
			i++;
		}
	}
	else
	{
		count += ft_print_str("(null)");
	}
	return (count);
}
