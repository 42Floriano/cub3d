/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:44 by albertini         #+#    #+#             */
/*   Updated: 2024/10/23 11:38:24 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_play_orient(t_game *game, char **map, int i, int j)
{
	if (map[i][j] == 'W')
	{
		game->diry = -1;
		game->planex = -0.66;
	}
	else if (map[i][j] == 'E')
	{
		game->diry = 1;
		game->planex = 0.66;
	}
	else if (map[i][j] == 'S')
	{
		game->dirx = 1;
		game->planey = -0.66;
	}
	else if (map[i][j] == 'N')
	{
		game->dirx = -1;
		game->planey = 0.66;
	}
	map[i][j] = '0';
}

	// if (y > SCREEN_HEIGHT)
	// 	y = SCREEN_HEIGHT - 50;
	// if (x > SCREEN_WIDTH)
	// 	x = SCREEN_WIDTH - 50;
void	my_mlx_pixel_put(t_game *g, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = g->img.pixels_ptr + (y * g->img.line_len + x * (g->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	raycasting(t_game *game)
{
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calculate_ray_position_and_direction(game, game->ray, x);
		calculate_initial_map_and_ray_lengths(game, game->ray);
		initialize_step_and_side_distances(game, game->ray);
		perform_dda(game, game->ray);
		render_wall_and_floor(game, game->ray, x);
		x++;
	}
}

// +0.5 is to center the player in the square
void	initialize_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->posx = i + 0.5;
				game->posy = j + 0.5;
				init_play_orient(game, game->map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

// Clear previous frame (if needed)
// Put the image to the window
// render_weapon(game);
void	render_frame(t_game *game)
{
	raycasting(game);
	mlx_put_image_to_window(game->mlx_connection,
		game->mlx_windows, game->img.img_ptr, 0, 0);
}
