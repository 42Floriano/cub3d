/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:29 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 12:57:14 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg++;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		num *= -1;
	return (num);
}
