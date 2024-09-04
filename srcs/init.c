/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:44 by albertini         #+#    #+#             */
/*   Updated: 2024/09/04 13:38:06 by falberti         ###   ########.fr       */
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
	game->map = NULL;
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
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		malloc_error();
	}
	game->img.img_ptr = mlx_new_image(game->mlx_connection,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->img.img_ptr == NULL)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_windows);
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		malloc_error();
	}
	game->img.pixels_ptr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.endian, &game->img.line_len);
}
