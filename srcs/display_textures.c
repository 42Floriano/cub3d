/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:29:00 by falberti          #+#    #+#             */
/*   Updated: 2024/09/25 15:53:45 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_texture	*choose_text(t_game *game, int side)
{
		printf("TEST position Side: %d\n", side);
	printf("TEST position Y: %f\n", game->ray.ray_dir_y);
	printf("TEST position X: %f\n", game->ray.ray_dir_x);
	if (side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			return (game->textures_list[EAST]);
		else
			return (game->textures_list[WEST]);
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
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
		wall_x = game->posy + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->posx + game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

// X-coordinate on the texture
static int	coordi_text(t_game *game, t_texture *texture, int tex_x, int side)
{
	if (side == 0 && game->ray.ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (side == 1 && game->ray.ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static inline double step(t_texture *texture, int draw_start, int draw_end)
{
	double	step;

	step = 0.0;
	step = 1.0 * texture->height / (draw_end - draw_start);
	return (step);
}

void	render_wall(t_game *game, int x, int draw_start, int draw_end, int side)
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
	texture = choose_text(game, side);
	tex_x = (int)(calc_p_wall(game, side) * (double)texture->width);
	coordi_text(game, texture, tex_x, side);
	// Calculate step size and initial texture position
	tex_pos = (draw_start - SCREEN_HEIGHT / 2 + (draw_end - draw_start) / 2)
		* step(texture, draw_start, draw_end);
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step(texture, draw_start, draw_end);
		my_mlx_pixel_put(game, x, y, texture->pixels[tex_y * texture->width + tex_x]);
		y++;
	}
}


// #include "../includes/cub3d.h"

// // Define wall colors for different orientations
// #define COLOR_NORTH 0xFF0000 // Red
// #define COLOR_SOUTH 0x00FF00 // Green
// #define COLOR_EAST  0x0000FF // Blue
// #define COLOR_WEST  0xFFFF00 // Yellow

// // Choose the color based on wall orientation and direction
// static int choose_color(t_game *game, int side)
// {
// 	printf("TEST position Side: %d\n", side);
// 	printf("TEST position Y: %f\n", game->ray.ray_dir_y);
// 	printf("TEST position X: %f\n", game->ray.ray_dir_x);
//     // Horizontal walls
//     if (side == 0)
//     {
//         if (game->ray.ray_dir_x > 0)
//             return COLOR_EAST; // East-facing wall
//         else
//             return COLOR_WEST; // West-facing wall
//     }
//     // Vertical walls
//     else
//     {
//         if (game->ray.ray_dir_y > 0)
//             return COLOR_SOUTH; // South-facing wall
//         else
//             return COLOR_NORTH; // North-facing wall
//     }
// }

// void render_wall(t_game *game, int x, int draw_start, int draw_end, int side)
// {
//     int color;
//     int y;

//     // Choose the color for the wall based on its orientation
//     color = choose_color(game, side);

//     // Render the wall with the chosen color
//     y = draw_start;
//     while (y < draw_end)
//     {
//         my_mlx_pixel_put(game, x, y, color);
//         y++;
//     }
// }
