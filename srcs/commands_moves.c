/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:39:38 by falberti          #+#    #+#             */
/*   Updated: 2024/10/23 11:44:51 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forw(t_game *game)
{
	double	next_posx;
	double	next_posy;

	next_posx = game->posx + game->dirx * MOVE_SPEED;
	next_posy = game->posy + game->diry * MOVE_SPEED;
	if (game->map[(int)next_posx][(int)game->posy] == '0')
		game->posx = next_posx;
	if (game->map[(int)game->posx][(int)next_posy] == '0')
		game->posy = next_posy;
}

void	move_back(t_game *game)
{
	double	next_posx;
	double	next_posy;

	next_posx = game->posx - game->dirx * MOVE_SPEED;
	next_posy = game->posy - game->diry * MOVE_SPEED;
	if (game->map[(int)next_posx][(int)game->posy] == '0')
		game->posx = next_posx;
	if (game->map[(int)game->posx][(int)next_posy] == '0')
		game->posy = next_posy;
}

void	move_left(t_game *game)
{
	double	next_posx;
	double	next_posy;

	next_posx = game->posx - game->planex * MOVE_SPEED;
	next_posy = game->posy - game->planey * MOVE_SPEED;
	if (game->map[(int)next_posx][(int)game->posy] == '0')
		game->posx = next_posx;
	if (game->map[(int)game->posx][(int)next_posy] == '0')
		game->posy = next_posy;
}

void	move_right(t_game *game)
{
	double	next_posx;
	double	next_posy;

	next_posx = game->posx + game->planex * MOVE_SPEED;
	next_posy = game->posy + game->planey * MOVE_SPEED;
	if (game->map[(int)next_posx][(int)game->posy] == '0')
		game->posx = next_posx;
	if (game->map[(int)game->posx][(int)next_posy] == '0')
		game->posy = next_posy;
}

void	rotate(t_game *game, int dir)
{
	double	old_dirx;
	double	old_planex;

	if (dir == LEFT)
	{
		old_dirx = game->dirx;
		game->dirx = game->dirx * cos(R_SPD) - game->diry * sin(R_SPD);
		game->diry = old_dirx * sin(R_SPD) + game->diry * cos(R_SPD);
		old_planex = game->planex;
		game->planex = game->planex * cos(R_SPD) - game->planey * sin(R_SPD);
		game->planey = old_planex * sin(R_SPD) + game->planey * cos(R_SPD);
	}
	else if (dir == RIGHT)
	{
		old_dirx = game->dirx;
		game->dirx = game->dirx * cos(-R_SPD) - game->diry * sin(-R_SPD);
		game->diry = old_dirx * sin(-R_SPD) + game->diry * cos(-R_SPD);
		old_planex = game->planex;
		game->planex = game->planex * cos(-R_SPD) - game->planey * sin(-R_SPD);
		game->planey = old_planex * sin(-R_SPD) + game->planey * cos(-R_SPD);
	}
	return ;
}
