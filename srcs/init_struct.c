/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:16:43 by falberti          #+#    #+#             */
/*   Updated: 2024/09/02 14:33:17 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_game *game)
{
	game->posx = 22;
	game->posy = 12;
	game->dirx = -1;
	game->diry = 0;
	game->planex = 0;
	game->planey = 0.66;
	game->time = 0;
	game->oldtime = 0;
	return ;
}
