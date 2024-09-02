/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/09/02 14:30:37 by aavduli          ###   ########.fr       */
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
# include <GLUT/glut.h>

//-----------------------------MAP----------------------------------------------
# define MAPX  8      //map width
# define MAPY  8      //map height
# define MAPS 64      //map cube size


/*
 0 = NORTH
 1 = SOUTH
 2 = EAST
 3 = WEST
*/

enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

typedef struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}			t_texture;

typedef struct s_player
{
	long	x;
	long	y;
	long	dirx;
	long	diry;
	long	planex;
	long	planey;
}				t_player;

typedef struct s_map
{
	char	**map;
	char	**copy_map;
	int		x;
	int		y;
	int		width;
	int		height;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_cmd		*cmd;
	t_map		*map;
	t_player	*player;
}				t_game;




//init
void	init_game(char *av, t_game *game);

//display
void	display();

//m_draw
void	draw_map2D();

//freerers

//lst_utils

//exit

#endif
