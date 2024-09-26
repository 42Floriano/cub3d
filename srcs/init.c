/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:44 by albertini         #+#    #+#             */
/*   Updated: 2024/09/26 12:35:40 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_game *game)
{
	game->name = "Cub3d";
	game->mlx_connection = NULL;
	game->mlx_windows = NULL;
	game->img.img_ptr = NULL;
	game->img.pixels_ptr = NULL;
	game->img.bpp = 0;
	game->img.endian = 0;
	game->img.line_len = 0;
	game->posx = 22;
	game->posy = 12;
	game->dirx = 0;
	game->diry = 0;
	game->planex = 0;
	game->planey = 0;
	game->time = 0;
	game->oldtime = 0;
	game->key_w = 0;
	game->key_a = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	return ;
}

void	ray_init(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->ray_dir_x = 0.0;
	ray->ray_dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->perp_wall_dist = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

//stupid norminette x)
static void	game_init_suite(t_game *game)
{
	game->img.pixels_ptr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.line_len, &game->img.endian);
	if (game->img.pixels_ptr == NULL)
	{
		mlx_destroy_image(game->mlx_connection, game->img.img_ptr);
		mlx_destroy_window(game->mlx_connection, game->mlx_windows);
		//mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		malloc_error();
	}
	game->ray = (t_ray *)malloc(sizeof(t_ray *) * 1);
	if (game->ray == NULL)
	{
		mlx_destroy_image(game->mlx_connection, game->img.img_ptr);
		mlx_destroy_window(game->mlx_connection, game->mlx_windows);
		//mlx_destroy_display(game->mlx_connection);
		free(game->img.pixels_ptr);
		free(game->mlx_connection);
		malloc_error();
	}
	load_texture_list(game);
}

void	game_init(t_game *game)
{
	data_init(game);
	game->mlx_connection = mlx_init();
	if (game->mlx_connection == NULL)
		malloc_error();
	game->mlx_windows = mlx_new_window(game->mlx_connection,
			SCREEN_WIDTH, SCREEN_HEIGHT, game->name);
	if (game->mlx_windows == NULL)
	{
		//mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		malloc_error();
	}
	game->img.img_ptr = mlx_new_image(game->mlx_connection,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->img.img_ptr == NULL)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_windows);
		//mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		malloc_error();
	}
	game_init_suite(game);
}
