/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:50:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/17 15:56:03 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	key_press(int keycode, t_game *game)
{
	if (keycode == KEYCODE_ESC)
	{
		end_game(game);
	}
	if (keycode == 119)
		game->key_w = 1;
	if (keycode == 115)
		game->key_s = 1;
	if (keycode == 97)
		game->key_a = 1;
	if (keycode == 100)
		game->key_d = 1;
	if (keycode == 65363)
		game->key_left = 1;
	if (keycode == 65361)
		game->key_right = 1;
	return (0);
}

static int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key_w = 0;
	if (keycode == 115)
		game->key_s = 0;
	if (keycode == 97)
		game->key_a = 0;
	if (keycode == 100)
		game->key_d = 0;
	if (keycode == 65363)
		game->key_left = 0;
	if (keycode == 65361)
		game->key_right = 0;
	return (0);
}

static int	close_cross(t_game *game)
{
	end_game(game);
	return (0);
}

void	hdl_movement(t_game *game)
{
	if (game->key_w)
		move_forw(game);
	if (game->key_s)
		move_back(game);
	if (game->key_a)
		move_left(game);
	if (game->key_d)
		move_right(game);
	if (game->key_left)
		rotate(game, LEFT);
	if (game->key_right)
		rotate(game, RIGHT);
}

void	commands(t_game *game)
{
	mlx_hook(game->mlx_windows, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_windows, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx_windows, 17, 0, close_cross, game);
}
