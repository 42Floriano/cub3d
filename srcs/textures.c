/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:23:17 by falberti          #+#    #+#             */
/*   Updated: 2024/09/26 13:37:37 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Function to allocate and load textures
void	load_texture(t_game *game, int i, char *path)
{
	printf("Loading texture from path:%s\n", path);
	game->textures_list[i]->img_ptr
		= mlx_xpm_file_to_image(game->mlx_connection, path,
			&game->textures_list[i]->width, &game->textures_list[i]->height);
	printf("%p\n", game->textures_list[i]->img_ptr);
	if (!game->textures_list[i]->img_ptr)
		exit_error(game, "Failed to load game->texture_north.");
	game->textures_list[i]->pixels
		= (int *)mlx_get_data_addr(game->textures_list[i]->img_ptr,
			&game->textures_list[i]->bpp,
			&game->textures_list[i]->line_len, &game->textures_list[i]->endian);
	printf("%p\n", game->textures_list[i]->pixels);
	if (!game->textures_list[i]->pixels)
		exit_error(game, "Failed to get texture data address.");
}

// Load all the textures during game initialization
void	load_texture_list(t_game *game)
{
	int	i;

	i = 0;
	game->textures_list = (t_texture **) malloc(sizeof(t_texture *) * 4);
	if (!game->textures_list)
		exit_error(game, "Memory allocation failed for texture.");
	while (i < 4)
	{
		game->textures_list[i] = (t_texture *)malloc(sizeof(t_texture));
		if (!game->textures_list[i])
			exit_error(game, "Memory allocation failed for texture.");
		i++;
	}
	// load_texture(game, SOUTH, "./textures/wall_south.xpm");
	// load_texture(game, NORTH, "./textures/wall_north.xpm");
	// load_texture(game, WEST, "./textures/wall_west.xpm");
	// load_texture(game, EAST, "./textures/wall_east.xpm");
	load_texture(game, SOUTH, game->paths.so_path);
	load_texture(game, NORTH,  game->paths.no_path);
	load_texture(game, WEST,  game->paths.we_path);
	load_texture(game, EAST, game->paths.ea_path);
}
