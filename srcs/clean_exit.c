/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/01 14:37:10 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
				mlx_destroy_image(game->mlx_connection,
					game->textures_list[i]->img_ptr);
			free(game->textures_list[i]);
		}
		i++;
	}
	free(game->textures_list);
}

void	free_paths(t_game *game)
{
	free(game->paths.ea_path);
	free(game->paths.we_path);
	free(game->paths.no_path);
	free(game->paths.so_path);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx_connection, game->mlx_windows);
	free_paths(game);
	if (game->textures_list != NULL)
		free_textures(game);
	if (game->map != NULL)
		free_array(game->map);
	if (game->dup_map != NULL)
		free_array(game->dup_map);
	if (game->ray != NULL)
		free(game->ray);
	exit(EXIT_SUCCESS);
}
