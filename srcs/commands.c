/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:50:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/26 12:41:36 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	key_press(int keycode, t_game *game)
{
	if (keycode == KEYCODE_ESC || keycode == 53)
	{
		end_game(game);
	}
	printf("Kypressed: %d\n", keycode);
	if (keycode == 119 || keycode == 13)
		game->key_w = 1;
	if (keycode == 115 || keycode == 1)
		game->key_s = 1;
	if (keycode == 97 || keycode == 0)
		game->key_a = 1;
	if (keycode == 100 || keycode == 2)
		game->key_d = 1;
	if (keycode == 65363 || keycode == 123)
		game->key_right = 1;
	if (keycode == 65361 || keycode == 124)
		game->key_left = 1;
	return (0);
}

static int	key_release(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 13)
		game->key_w = 0;
	if (keycode == 115 || keycode == 1)
		game->key_s = 0;
	if (keycode == 97 || keycode == 0)
		game->key_a = 0;
	if (keycode == 100 || keycode == 2)
		game->key_d = 0;
	if (keycode == 65363 || keycode == 123)
		game->key_right = 0;
	if (keycode == 65361 || keycode == 124)
		game->key_left = 0;
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
