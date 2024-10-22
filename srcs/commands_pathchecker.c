/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_pathchecker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:13:28 by albertini         #+#    #+#             */
/*   Updated: 2024/10/22 15:13:41 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	calculate_steps(t_movement *move)
{
	move->step_x = move->delta_x / move->distance;
	move->step_y = move->delta_y / move->distance;
	return ((int)(move->distance / 0.1));
}

static bool	check_path_for_walls(t_game *game, t_movement *move, int num_steps)
{
	double	check_x;
	double	check_y;
	int		i;

	check_x = game->posx;
	check_y = game->posy;
	i = 0;
	while (i < num_steps)
	{
		check_x += move->step_x;
		check_y += move->step_y;
		if (game->map[(int)check_x][(int)check_y] != '0')
			return (false);
		i++;
	}
	return (true);
}

bool	is_path_clear(t_game *game, double end_x, double end_y)
{
	t_movement	move;
	int			num_steps;

	move.delta_x = end_x - game->posx;
	move.delta_y = end_y - game->posy;
	move.distance = sqrt(move.delta_x * move.delta_x
			+ move.delta_y * move.delta_y);
	num_steps = calculate_steps(&move);
	return (check_path_for_walls(game, &move, num_steps));
}
