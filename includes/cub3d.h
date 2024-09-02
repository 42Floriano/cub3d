/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/02 14:33:53 by falberti         ###   ########.fr       */
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

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480


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

typedef struct s_cmd	t_cmd;

typedef struct s_game
{
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
void	init_game(t_game *game);

//safe_functions

//freerers

//lst_utils

//exit

#endif
