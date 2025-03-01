/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:20 by falberti          #+#    #+#             */
/*   Updated: 2024/02/23 16:27:33 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ischar(char csep, char c)
{
	if (csep == c)
		return (1);
	return (0);
}

static int	count_words(char const *str, char csep)
{
	int	i;
	int	count;
	int	trigger;

	i = 0;
	count = 0;
	trigger = 0;
	while (str[i])
	{
		if (ischar(csep, str[i]) == 0 && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (ischar(csep, str[i]) == 1)
		{
			trigger = 0;
		}
		i++;
	}
	return (count);
}

static int	count_char(char const *str, char csep)
{
	int	i;

	i = 0;
	while (str[i] && ischar(csep, str[i]) == 0)
	{
		i++;
	}
	return (i);
}

static char	*create_new(char const *str, char csep, int pos)
{
	char	*nstr;
	int		i;
	int		len;

	i = 0;
	len = count_char(&str[pos], csep);
	nstr = (char *) malloc(sizeof(char) * len + 1);
	if (nstr == 0)
		return (nstr);
	while (i < len)
	{
		nstr[i] = str[pos];
		i++;
		pos++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		y;
	char	**liste;

	liste = (char **) malloc(sizeof(*liste) * (count_words(s, c) + 1));
	if (liste == 0)
		return (liste);
	i = 0;
	y = 0;
	while (s[i])
	{
		while (ischar(c, s[i]) == 1 && s[i])
			i++;
		if (s[i])
		{
			liste[y] = create_new(s, c, i);
			y++;
		}
		while (ischar(c, s[i]) == 0 && s[i])
			i++;
	}
	liste[y] = 0;
	return (liste);
}
