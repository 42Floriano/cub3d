/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:53:21 by albertini         #+#    #+#             */
/*   Updated: 2024/08/27 11:48:08 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac == 2)
	{
		init_game(av[1], &game);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	}
	return (0);
}
