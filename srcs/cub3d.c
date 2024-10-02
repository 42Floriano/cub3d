/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:53:21 by albertini         #+#    #+#             */
/*   Updated: 2024/10/02 14:55:07 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	data_init_bis(t_game *game)
{
	game->paths.no_path = NULL;
	game->paths.so_path = NULL;
	game->paths.we_path = NULL;
	game->paths.ea_path = NULL;
	game->map = NULL;
	game->paths.c_color = 0;
	game->paths.f_color = 0;
}

static inline int	av_checker(char *str)
{
	int	i;

	i = (ft_strlen(str) - 1);
	if (str[i - 3] == '.' && str[i - 2] == 'c'
		&& str[i - 1] == 'u' && str[i] == 'b')
		return (0);
	return (1);
}

static	int	main_loop(t_game *game)
{
	render_frame(game);
	display_fps(game);
	hdl_movement(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || av_checker(av[1]))
		printf("Error\nInvalid Syntax\nPlease pass .cub file");
	else
	{
		game_init(&game);
		ray_init(&game);
		init_parsing(av[1], &game);
		load_texture_list(&game);
		check_map(&game);
		commands(&game);
		initialize_player(&game);
		mlx_loop_hook(game.mlx_connection, &main_loop, &game);
		mlx_loop(game.mlx_connection);
	}
	return (1);
}
