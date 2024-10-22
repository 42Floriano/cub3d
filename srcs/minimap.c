/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:04:48 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/22 12:05:14 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define MINIMAP_SCALE 10  // Chaque carré de la carte sera réduit par un facteur de 10

void	render_minimap(t_game *game)
{
	int map_x;
	int map_y;
	int pixel_x;
	int pixel_y;
	int color;

	// Initialisation de la boucle pour parcourir les lignes de la carte
	map_y = 0;
	while (map_y < game->map_height)
	{
		// Initialisation de la boucle pour parcourir les colonnes de la carte
		map_x = 0;
		while (map_x < game->map_width)
		{
			// Choisir la couleur selon le type de case
			if (game->map[map_y][map_x] == '1')  // Mur
				color = 0xFFFFFF;  // Blanc pour les murs
			else if (game->map[map_y][map_x] == '0')  // Vide
				color = 0x000000;  // Noir pour les espaces vides
			else
				color = 0x00FF00;  // Autre (portes, objets, etc.)

			// Dessiner un carré pour chaque case de la carte
			pixel_y = 0;
			while (pixel_y < MINIMAP_SCALE)
			{
				pixel_x = 0;
				while (pixel_x < MINIMAP_SCALE)
				{
					my_mlx_pixel_put(game, map_x * MINIMAP_SCALE + pixel_x,
						map_y * MINIMAP_SCALE + pixel_y, color);
					pixel_x++;
				}
				pixel_y++;
			}

			// Passer à la prochaine case de la carte
			map_x++;
		}

		// Passer à la prochaine ligne de la carte
		map_y++;
	}

	// Dessiner la position du joueur sur la mini-carte
	int player_map_x = (int)(game->posx * MINIMAP_SCALE);
	int player_map_y = (int)(game->posy * MINIMAP_SCALE);

	// Dessiner le joueur comme un petit carré rouge
	pixel_y = -2;
	while (pixel_y <= 2)
	{
		pixel_x = -2;
		while (pixel_x <= 2)
		{
			my_mlx_pixel_put(game, player_map_x + pixel_x, player_map_y + pixel_y, 0xFF0000);  // Rouge
			pixel_x++;
		}
		pixel_y++;
	}
}
