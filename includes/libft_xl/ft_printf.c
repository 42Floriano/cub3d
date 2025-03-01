/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:18:48 by falberti          #+#    #+#             */
/*   Updated: 2024/03/06 10:51:50 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkandprint_type(char spe, va_list ap)
{
	int	count;

	count = 0;
	if (spe == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (spe == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (spe == 'i' || spe == 'd')
		count += ft_print_int(va_arg(ap, int));
	else if (spe == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;
	int		i;

	count = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_checkandprint_type(format[i + 1], ap);
			i++;
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
