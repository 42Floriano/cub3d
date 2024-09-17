/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/17 13:33:09 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_sky(t_game *game)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	y = 0; // Start from the top of the screen
	while (y < SCREEN_HEIGHT / 2)  // Sky is rendered on the top half of the screen
	{
		x = 0;
		while (x < SCREEN_WIDTH)  // Iterate over the width of the screen
		{
			tex_x = x % game->sky_texture.width;  // Calculate the corresponding texture x-coordinate
			tex_y = y % game->sky_texture.height; // Calculate the corresponding texture y-coordinate
			color = game->sky_texture.pixels[tex_y * game->sky_texture.width + tex_x];  // Get the pixel color from the texture
			my_mlx_pixel_put(game, x, y, color);  // Render the pixel on the screen
			x++;
		}
		y++;
	}
}

void	render_floor(t_game *game)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	y = SCREEN_HEIGHT / 2;  // Start from the middle of the screen (where the floor starts)
	while (y < SCREEN_HEIGHT)  // Floor is rendered on the bottom half of the screen
	{
		x = 0;
		while (x < SCREEN_WIDTH)  // Iterate over the width of the screen
		{
			tex_x = x % game->floor_texture.width;  // Calculate the corresponding texture x-coordinate
			tex_y = y % game->floor_texture.height; // Calculate the corresponding texture y-coordinate
			color = game->floor_texture.pixels[tex_y * game->floor_texture.width + tex_x];  // Get the pixel color from the texture
			my_mlx_pixel_put(game, x, y, color);  // Render the pixel on the screen
			x++;
		}
		y++;
	}
}
