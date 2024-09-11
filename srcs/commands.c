/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:50:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/11 15:00:38 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

static int	read_keys(int keypress, t_game *game)
{
	double	next_posx;
	double	next_posy;
	double	old_dirx;
	double	old_planex;

	// printf("TEST: %d\n", keypress);
	// if (keypress == KEYCODE_ESC)
	// {
	// 	ft_printf("The %d key (ESC) has been pressed\n", keypress);
	// 	end_game(game);
	// }
	// Move forward (W key)
	if (keypress == 119)
	{
		next_posx = game->posx + game->dirx * MOVE_SPEED;
		next_posy = game->posy + game->diry * MOVE_SPEED;
		if (game->map[(int)next_posx][(int)game->posy] == '0')
			game->posx = next_posx;
		if (game->map[(int)game->posx][(int)next_posy] == '0')
			game->posy = next_posy;
	}

	// Move backward (S key)
	if (keypress == 115)
	{
		next_posx = game->posx - game->dirx * MOVE_SPEED;
		next_posy = game->posy - game->diry * MOVE_SPEED;
		if (game->map[(int)next_posx][(int)game->posy] == '0')
			game->posx = next_posx;
		if (game->map[(int)game->posx][(int)next_posy] == '0')
			game->posy = next_posy;
	}

	// Strafe left (A key)
	if (keypress == 97)
	{
		next_posx = game->posx - game->planex * MOVE_SPEED;
		next_posy = game->posy - game->planey * MOVE_SPEED;
		if (game->map[(int)next_posx][(int)game->posy] == '0')
			game->posx = next_posx;
		if (game->map[(int)game->posx][(int)next_posy] == '0')
			game->posy = next_posy;
	}

	// Strafe right (D key)
	if (keypress == 100)
	{
		next_posx = game->posx + game->planex * MOVE_SPEED;
		next_posy = game->posy + game->planey * MOVE_SPEED;
		if (game->map[(int)next_posx][(int)game->posy] == '0')
			game->posx = next_posx;
		if (game->map[(int)game->posx][(int)next_posy] == '0')
			game->posy = next_posy;
	}

	// Rotate right (right arrow key)
	if (keypress == 65361)
	{
		old_dirx = game->dirx;
		game->dirx = game->dirx * cos(-ROT_SPEED) - game->diry * sin(-ROT_SPEED);
		game->diry = old_dirx * sin(-ROT_SPEED) + game->diry * cos(-ROT_SPEED);
		
		old_planex = game->planex;
		game->planex = game->planex * cos(-ROT_SPEED) - game->planey * sin(-ROT_SPEED);
		game->planey = old_planex * sin(-ROT_SPEED) + game->planey * cos(-ROT_SPEED);
	}

	// Rotate left (left arrow key)
	if (keypress == 65363)
	{
		old_dirx = game->dirx;
		game->dirx = game->dirx * cos(ROT_SPEED) - game->diry * sin(ROT_SPEED);
		game->diry = old_dirx * sin(ROT_SPEED) + game->diry * cos(ROT_SPEED);
		
		old_planex = game->planex;
		game->planex = game->planex * cos(ROT_SPEED) - game->planey * sin(ROT_SPEED);
		game->planey = old_planex * sin(ROT_SPEED) + game->planey * cos(ROT_SPEED);
	}

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
