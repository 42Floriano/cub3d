/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:44 by albertini         #+#    #+#             */
/*   Updated: 2024/09/17 14:29:23 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_play_orient(t_game *game, char **map, int i, int j)
{
	if (map[i][j] == 'N')
	{
		game->diry = -1;
		game->planex = 0.66;
	}
	else if (map[i][j] == 'S')
	{
		game->diry = 1;
		game->planex = -0.66;
	}
	else if (map[i][j] == 'E')
	{
		game->dirx = 1;
		game->planey = 0.66;
	}
	else if (map[i][j] == 'W')
	{
		game->dirx = -1;
		game->planey = -0.66;
	}
}

void	my_mlx_pixel_put(t_game *g, int x, int y, int color)
{
	char	*dst;

	dst = g->img.pixels_ptr + (y * g->img.line_len + x * (g->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	ray_init(&ray);
	while (x < SCREEN_WIDTH)
	{
		calculate_ray_position_and_direction(game, &ray, x);
		calculate_initial_map_and_ray_lengths(game, &ray);
		initialize_step_and_side_distances(game, &ray);
		perform_dda(game, &ray);
		render_wall_and_floor(game, &ray, x);
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
void	render_frame(t_game *game)
{
	raycasting(game);
	mlx_put_image_to_window(game->mlx_connection,
		game->mlx_windows, game->img.img_ptr, 0, 0);
}
