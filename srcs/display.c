/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:44 by albertini         #+#    #+#             */
/*   Updated: 2024/09/11 14:41:37 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void    my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char    *dst;

	dst = game->img.pixels_ptr + (y * game->img.line_len + x * (game->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void raycasting(t_game *game)
{
	int x;
	double camera_x;
	double ray_dir_x;
	double ray_dir_y;
	int map_x;
	int map_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	double perp_wall_dist;
	int step_x;
	int step_y;
	int hit;
	int side;
	int line_height;
	int draw_start;
	int draw_end;
	int y;

	// Define floor and ceiling colors
	int floor_color = 0x333333;  // Dark grey for the floor
	int ceiling_color = 0x87CEEB;  // Sky blue for the ceiling
	int wall_color;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		// Calculate ray position and direction
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_dir_x = game->dirx + game->planex * camera_x;
		ray_dir_y = game->diry + game->planey * camera_x;

		// Initial map position
		map_x = (int)game->posx;
		map_y = (int)game->posy;

		// Length of ray from current position to next x or y-side
		delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
		delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

		// Initialize step and side distances
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->posx - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->posx) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->posy - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->posy) * delta_dist_y;
		}

		// Perform DDA to find wall hit
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}

			// Check if ray hits a wall
			if (game->map[map_x][map_y] == '1')
				hit = 1;
		}

		// Calculate distance to the wall
		if (side == 0)
			perp_wall_dist = (map_x - game->posx + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->posy + (1 - step_y) / 2) / ray_dir_y;

		// Calculate the height of the wall line
		line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);

		// Calculate the lowest and highest pixel to fill in the current stripe
		draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;

		// Draw ceiling from the top of the screen to the start of the wall
		y = 0;
		while (y < draw_start)
		{
			my_mlx_pixel_put(game, x, y, ceiling_color);
			y++;
		}

		// Set color for the wall based on the side hit
		if (side == 0)
			wall_color = 0xFF0000; // Red for X side
		else
			wall_color = 0x00FF00; // Green for Y side

		// Draw the wall slice
		while (y < draw_end)
		{
			my_mlx_pixel_put(game, x, y, wall_color);
			y++;
		}

		// Draw floor from the bottom of the wall to the bottom of the screen
		while (y < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(game, x, y, floor_color);
			y++;
		}

		// Move to the next vertical stripe
		x++;
	}
}

void    initialize_player(t_game *game, char **map)
{
	int i = 0;
	int j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				game->posx = j + 0.5; // Player's X position (centered in the square)
				game->posy = i + 0.5; // Player's Y position (centered in the square)

				// Set the direction based on the orientation
				if (map[i][j] == 'N')
				{
					game->dirx = 0;
					game->diry = -1;
					game->planex = 0.66;
					game->planey = 0;
				}
				else if (map[i][j] == 'S')
				{
					game->dirx = 0;
					game->diry = 1;
					game->planex = -0.66;
					game->planey = 0;
				}
				else if (map[i][j] == 'E')
				{
					game->dirx = 1;
					game->diry = 0;
					game->planex = 0;
					game->planey = 0.66;
				}
				else if (map[i][j] == 'W')
				{
					game->dirx = -1;
					game->diry = 0;
					game->planex = 0;
					game->planey = -0.66;
				}

				// Replace the player's starting position with empty space
				map[i][j] = '0';
				return;
			}
			j++;
		}
		i++;
	}
}


void render_frame(t_game *game)
{
	// Clear previous frame (if needed)
	raycasting(game);

	// Put the image to the window
	mlx_put_image_to_window(game->mlx_connection, game->mlx_windows, game->img.img_ptr, 0, 0);
}
