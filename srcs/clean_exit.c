/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:30:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/26 11:06:06 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_error(t_game *game, char *msg)
{
	clean_pars(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	clean_pars(t_game *game)
{
	(void)game;
	return ;
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx_connection, game->mlx_windows);
	//mlx_destroy_display(game->mlx_connection);
	//free(game->mlx_connection);
	free_textures(game);
	free(game->ray);
	clean_pars(game);
	exit(EXIT_SUCCESS);
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
