/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:50:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/04 14:59:27 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

static int	read_keys(int keypress, t_game *game)
{
	printf("TEST: %d\n", keypress);
	if (keypress == KEYCODE_ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n", keypress);
		end_game(game);
	}
	else if (keypress == KEYCODE_D)
		printf("playermove(1, game)");
	else if (keypress == KEYCODE_A)
		printf("playermove(2, game)");
	else if (keypress == KEYCODE_W)
		printf("playermove(3, game)");
	else if (keypress == KEYCODE_S)
		printf("playermove(4, game)");
	else if (keypress == KEYCODE_RIGHT_ARROW)
		printf("playermove(5, game)");
	else if (keypress == KEYCODE_LEFT_ARROW)
		printf("playermove(6, game)");

	return (0);
}

static int	close_cross(t_game *game)
{
	end_game(game);
	return (0);
}

void	commands(t_game *game)
{
	mlx_hook(game->mlx_windows, 2, 1L<<0, read_keys, game);
	mlx_hook(game->mlx_windows, 17, 0, close_cross, game);
}
