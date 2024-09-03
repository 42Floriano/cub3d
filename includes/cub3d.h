/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/03 11:15:58 by albertini        ###   ########.fr       */
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

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 1080


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

//display
void	display();

//m_draw
void	draw_map2D();

//freerers

//lst_utils

//exit

#endif
