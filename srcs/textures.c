/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:23:17 by falberti          #+#    #+#             */
/*   Updated: 2024/09/17 15:35:03 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Function to load textures
// static void	load_texture(t_game *game, t_texture *texture, char *path)
// {
// 	printf("Loading texture from path: %s\n", path);
// 	texture->img_ptr = mlx_xpm_file_to_image(game->mlx_connection,
// 			path, &texture->width, &texture->height);
// 	if (!texture->img_ptr)
// 		exit_error(game, "Failed to load texture.");
// 	texture->pixels = (int *)mlx_get_data_addr(texture->img_ptr,
// 			&texture->bpp, &texture->line_len, &texture->endian);
// }

// // Load all the textures during game initialization
// void	load_textures(t_game *game)
// {
// 	load_texture(game, &game->texture_north, "../textures/north_wall.xpm");
// 	load_texture(game, &game->texture_south, "../textures/south_wall.xpm");
// 	load_texture(game, &game->texture_west, "../textures/west_wall.xpm");
// 	load_texture(game, &game->texture_east, "../textures/east_wall.xpm");
// 	// load_texture(game, &game->sky_texture, "../textures/floor_3.xmp");
// 	//load_texture(game, &game->floor_texture, "../textures/floor_3.xpm");
// }
