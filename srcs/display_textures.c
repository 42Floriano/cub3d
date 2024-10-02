/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:00 by falberti          #+#    #+#             */
/*   Updated: 2024/10/02 16:35:53 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_texture	*choose_text(t_game *game, int side)
{
	if (side == 0)
	{
		if (game->ray->ray_dir_x > 0)
			return (game->textures_list[EAST]);
		else
			return (game->textures_list[WEST]);
	}
	else
	{
		if (game->ray->ray_dir_y > 0)
			return (game->textures_list[SOUTH]);
		else
			return (game->textures_list[NORTH]);
	}
}

// Calculate the exact position on the wall
static double	calc_p_wall(t_game *game, int side)
{
	double	wall_x;

	wall_x = 0.0;
	if (side == 0)
		wall_x = game->posy + game->ray->perp_wall_dist * game->ray->ray_dir_y;
	else
		wall_x = game->posx + game->ray->perp_wall_dist * game->ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

// X-coordinate on the texture
static int	coordi_text(t_game *game, t_texture *texture, int tex_x, int side)
{
	if (side == 0 && game->ray->ray_dir_x < 0)
		tex_x = texture->width - tex_x - 1;
	if (side == 1 && game->ray->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

// Calculate step size and initial texture position
static inline double	step(t_texture *texture, int draw_start, int draw_end)
{
	double	step;

	step = 0.0;
	step = 1.0 * texture->height / (draw_end - draw_start);
	return (step);
}

void	render_wall(t_game *game, int x, t_ray *ray)
{
	t_texture	*texture;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	int			y;

	tex_x = 0;
	tex_y = 0;
	tex_pos = 0.0;
	texture = NULL;
	texture = choose_text(game, ray->side);
	tex_x = (int)(calc_p_wall(game, ray->side) * (double)texture->width);
	tex_x = coordi_text(game, texture, tex_x, ray->side);
	tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2
			+ (ray->draw_end - ray->draw_start)
			/ 2) * step(texture, ray->draw_start, ray->draw_end);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step(texture, ray->draw_start, ray->draw_end);
		my_mlx_pixel_put(game, x, y,
			texture->pixels[tex_y * texture->width + tex_x]);
		y++;
	}
}

// void	render_weapon(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	x = (SCREEN_WIDTH - game->textures_list[4]->width) / 2;
// 	y = SCREEN_HEIGHT - game->textures_list[4]->height ;
// 	mlx_put_image_to_window(game->mlx_connection,
//			game->mlx_windows, game->textures_list[4]->img_ptr, x, y);
// }
