/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:39:38 by falberti          #+#    #+#             */
/*   Updated: 2024/09/17 13:12:33 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double	calculate_fps(t_game *game)
{
	double	frametime;
	double	fps;

	game->fps_oldtime = game->fps_time;
	gettimeofday(&game->fps_time, NULL);
	frametime = (game->fps_time.tv_sec - game->fps_oldtime.tv_sec)
		+ (game->fps_time.tv_usec - game->fps_oldtime.tv_usec) / 1000000.0;
	fps = 1.0 / frametime;
	return (fps);
}

void	display_fps(t_game *game)
{
	char	fps_text[50];
	double	fps;

	fps = calculate_fps(game);
	snprintf(fps_text, sizeof(fps_text), "FPS: %.2f", fps);
	mlx_string_put(game->mlx_connection,
		game->mlx_windows, 30, 30, 0xFFFFFF, fps_text);
}
