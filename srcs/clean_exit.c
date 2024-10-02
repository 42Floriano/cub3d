/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/02 14:45:22 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

void	exit_parsing(t_game *game)
{
	if (game->paths.no_path)
	{
		free(game->paths.no_path);
		game->paths.no_path = NULL;
	}
	if (game->paths.so_path)
	{
		free(game->paths.so_path);
		game->paths.so_path = NULL;
	}
	if (game->paths.we_path)
	{
		free(game->paths.we_path);
		game->paths.we_path = NULL;
	}
	if (game->paths.ea_path)
	{
		free(game->paths.ea_path);
		game->paths.ea_path = NULL;
	}
	if (game->map)
		free_array(game->map);
	exit(EXIT_FAILURE);
}

int	exit_error(t_game *game, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	end_game(game);
	exit(EXIT_FAILURE);
}

void	free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures_list[i])
		{
			if (game->textures_list[i]->img_ptr)
			{
				mlx_destroy_image(game->mlx_connection,
					game->textures_list[i]->img_ptr);
			}
			free(game->textures_list[i]);
		}
		i++;
	}
	free(game->textures_list);
}

void	free_paths(t_game *game)
{
	if (game->paths.no_path)
		free(game->paths.no_path);
	if (game->paths.so_path)
		free(game->paths.so_path);
	if (game->paths.we_path)
		free(game->paths.we_path);
	if (game->paths.ea_path)
		free(game->paths.ea_path);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx_connection, game->mlx_windows);
	free_paths(game);
	if (game->textures_list != NULL)
		free_textures(game);
	if (game->map != NULL)
		free_array(game->map);
	if (game->ray != NULL)
		free(game->ray);
	game->ray = NULL;
	exit(EXIT_SUCCESS);
}
