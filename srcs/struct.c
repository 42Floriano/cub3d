/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:11:06 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/28 13:21:06 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.dirx = -1;
	game->player.diry = 0;
	game->player.planex = 0;
	game->player.planey = 0;
	game->map->map = NULL;
}
