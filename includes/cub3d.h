/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/22 12:05:29 by aavduli          ###   ########.fr       */
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
# include <sys/time.h>

# define MAP_WIDTH 29
# define MAP_HEIGHT 13
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 1080
# define FLOOR_COLOR 0x00FF00
# define CEILING_COLOR 0x87CEEB

/* SELECTORS */
# define NO				0
# define YES 			1

# define CUB 			1

# define TEXTURE		1
# define COLOR			2

# define NORTH			1
# define SOUTH			0
# define EAST			3
# define WEST			2
# define FLOOR			5
# define CEILING		6

# define RIGHT			1
# define LEFT			0

# define MOVE_SPEED 	0.04
# define R_SPD 			0.1

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

enum e_type
{
	typeOne,
};

typedef struct s_movement
{
	double	delta_x;
	double	delta_y;
	double	distance;
	double	step_x;
	double	step_y;
}	t_movement;

typedef struct s_texture
{
	void	*img_ptr;
	int		*pixels;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_path
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*weapon;
	int		f_color;
	int		c_color;
}			t_path;

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

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_game
{
	char			*name;
	void			*mlx_connection;
	void			*mlx_windows;
	t_img			img;
	t_ray			*ray;
	char			**map;
	char			**dup_map;
	int				array_size;
	int				map_width;
	int				map_height;
	double			map_y;
	double			map_x;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	struct timeval	fps_time;
	struct timeval	fps_oldtime;
	t_texture		**textures_list;
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_left;
	int				key_right;
	t_path			paths;
	int				player;
}	t_game;

//init_structs.c
void	data_init(t_game *game);
void	game_init(t_game *game);
void	ray_init(t_game *game);

//init_structs
void	data_init(t_game *game);
void	data_init_bis(t_game *game);
void	game_init(t_game *game);
void	ray_init(t_game *ray);

//init.c
void	init_game(char *av, t_game *game);
void	launch_mlx(t_game *game);

//parsing
void	init_parsing(char *av, t_game *game);
int		check_double(t_game *game, char *line);
void	parsing2(t_game *game, char *av);

//mapping
void	malloc_mapy(t_game *game, char *line, int fd);
void	copy_map(t_game *game, char *av);

//minimnap
void	render_minimap(t_game *game);

//map_utils
void	check_map(t_game *game);
int		max_lenght(t_game *game);
void	make_it_rectangle(t_game *game, int max_size);
int		is_valid(t_game *game, char c, int i, int j);

//display.c
void	raycasting(t_game *game);
void	render_frame(t_game *game);
void	initialize_player(t_game *game);
void	my_mlx_pixel_put(t_game *g, int x, int y, int color);
void	my_mlx_pixel_put_text(t_texture *text, int x, int y, int color);

//display_utils.c
void	calculate_ray_position_and_direction(t_game *game, t_ray *ray, int x);
void	calculate_initial_map_and_ray_lengths(t_game *game, t_ray *ray);
void	initialize_step_and_side_distances(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	render_wall_and_floor(t_game *game, t_ray *ray, int x);

//freerers
void	free_array(char **map);

//read_map
char	**readmap(char *filename);

//Commands.c
void	commands(t_game *game);
void	hdl_movement(t_game *game);

//Commands_moves.c
void	move_forw(t_game *game);
void	move_back(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate(t_game *game, int dir);

//command_pathchecker.c
bool	is_path_clear(t_game *game, double end_x, double end_y);
void	check_file(t_game *game, char *file);

//clean_exit.c
int		exit_error(t_game *game, char *msg);
void	clean_pars(t_game *game);
int		end_game(t_game *game);
void	free_textures(t_game *game);

//safe_function
int		safe_open(t_game *game, char *av);
void	*safe_malloc(size_t bytes);
int		is_digit(char **tab);
int		check_params(t_game *game);

//exit
void	exit_parsing(t_game *game);

//fps_display.c
void	display_fps(t_game *game);

//textures.c
void	load_texture_list(t_game *game);

//display_textures.c
void	render_wall(t_game *game, int x, t_ray *ray);
void	render_weapon(t_game *game);

#endif
