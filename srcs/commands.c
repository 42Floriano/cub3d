/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:50:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/17 15:10:49 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	read_keys(int keypress, t_game *game)
{
	printf("TEST: %d\n", keypress);
	printf("posex: %f\n", game->posx);
	printf("posey: %f\n", game->posy);
	printf("game->map[(int)game->posx][(int)game->posy]: %c\n", game->map[(int)game->posx][(int)game->posy]);
	if (keypress == KEYCODE_ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n", keypress);
		end_game(game);
	}
	// Move forward (W key)
	if (keypress == 119)
		move_forw(game);
	// Move backward (S key)
	if (keypress == 115)
		move_back(game);
	// Strafe left (A key)
	if (keypress == 97)
		move_left(game);
	// Strafe right (D key)
	if (keypress == 100)
		move_right(game);
	// Rotate right (right arrow key)
	if (keypress == 65361)
		rotate(game, RIGHT);
	// Rotate left (left arrow key)
	if (keypress == 65363)
		rotate(game, LEFT);
	return (0);
}

static int	close_cross(t_game *game)
{
	end_game(game);
	return (0);
}

void	commands(t_game *game)
{
	mlx_hook(game->mlx_windows, 2, 1L << 0, read_keys, game);
	mlx_hook(game->mlx_windows, 17, 0, close_cross, game);
}
