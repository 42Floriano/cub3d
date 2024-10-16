/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:53:21 by albertini         #+#    #+#             */
/*   Updated: 2024/10/16 17:06:03 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		check_file(&game, av[1]);
		init_parsing(av[1], &game);
		load_texture_list(&game);
		check_map(&game);
		commands(&game);
		printf("Map widt: %d, height: %d\n", game.map_width, game.map_height);
		initialize_player(&game);
		mlx_loop_hook(game.mlx_connection, &main_loop, &game);
		mlx_loop(game.mlx_connection);
	}
	return (1);
}
