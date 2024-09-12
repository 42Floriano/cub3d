/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/12 14:58:41 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft_xl/libft.h"
# include "keybinds.h"
# include <stdbool.h>

# define MAP_WIDTH 6
# define MAP_HEIGHT 5
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 1080
# define FLOOR_COLOR 0x333333
# define CEILING_COLOR 0x87CEEB

/* SELECTORS */
# define NO				0
# define YES 			1

# define CUB 			1

# define TEXTURE		1
# define COLOR			2

# define NORTH			1
# define SOUTH			2
# define EAST			3
# define WEST			4
# define FLOOR			5
# define CEILING		6

# define RIGHT			1
# define LEFT			0

# define MOVE_SPEED 	0.1
# define R_SPD 			0.05

/* ERROR MESSAGES */
# define ERR_ARGS		"Invalid number of arguments"

# define ERR_CUB		"Invalid input file name"
# define ERR_CUB_EXT	"Input file must be .cub"
# define ERR_CUB_OPEN	"Couldn't open input file"

# define ERR_XPM		"Invalid texture file name"
# define ERR_XPM_EXT	"Asset file must be .xpm"
# define ERR_XPM_OPEN	"Couldn't open texture file"
# define ERR_XPM_RPT	"Has repeated textures in this input file"
# define ERR_XPM_CALL	"Has repeated textures calls in this input file"
# define ERR_TEXTURE	"Invalid texture file"

# define ERR_COLOR_FMT	"Color format must be R,G,B"
# define ERR_COLOR_NUM	"Colors must have only positive numbers"
# define ERR_COLOR_RANG "Colors must be between 0 and 255"
# define ERR_COLOR_CALL	"Has repeated colors calls in this input file"

# define ERR_INVALID	"The input file has invalid parameters"
# define ERR_PARAMS		"The input file doesn't have all necessary parameters"

# define ERR_MAP_EMPTY	"Map is not configured correctly"
# define ERR_MAP_WALLS	"The map isn't well surrounded by walls"
# define ERR_MAP_CHARS	"Invalid character in map"
# define ERR_MAP_MSPAWN	"Multiple spawn points"
# define ERR_MAP_NSPAWN	"No spawn point"

/*
 0 = 
 1 = 
 2 =
 3 = 
 4 = 
 5 = 
 6 = 
 7 = 
 8 = 
 9 = 
 10 = 
*/

enum e_type
{
	typeOne,
};

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct	s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_game
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_windows;
	t_img	img;
	t_ray	ray;
	char	**map;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
}	t_game;


//init_structs
void	data_init(t_game *game);
void	game_init(t_game *game);
void	ray_init(t_ray *ray);

//display
void    raycasting(t_game *game);
void	render_frame(t_game *game);
void    initialize_player(t_game *game, char **map);
void	my_mlx_pixel_put(t_game *g, int x, int y, int color);

//display_utils
void	calculate_ray_position_and_direction(t_game *game, t_ray *ray, int x);
void	calculate_initial_map_and_ray_lengths(t_game *game, t_ray *ray);
void	initialize_step_and_side_distances(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	render_wall_and_floor(t_game *game, t_ray *ray, int x);

//freerers

//read_map
char	**readmap(char *filename);

//Commands
void	commands(t_game *game);

//Commands_utils
void	move_forw(t_game *game);
void	move_back(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate(t_game *game, int dir);

//clean_exit
int		exit_error(t_game *game, char *msg);
void	clean_pars(t_game *game);
int		end_game(t_game *game);

#endif
