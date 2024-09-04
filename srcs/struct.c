/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:11:06 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/03 13:26:39 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_game *game)
{
	game->map->map = NULL;
	game->map->copy_map = NULL;
	game->texture->no_path = NULL;
	game->texture->so_path = NULL;
	game->texture->we_path = NULL;
	game->texture->ea_path = NULL;
}
