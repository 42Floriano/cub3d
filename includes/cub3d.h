/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:46:15 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/02 14:46:50 by aavduli          ###   ########.fr       */
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

//-----------------------------MAP----------------------------------------------
# define MAPX  8      //map width
# define MAPY  8      //map height
# define MAPS 64      //map cube size


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

struct s_cmd
{
	char			*str;
	int				type;
	bool			pipe;
	t_cmd			*next;
	t_cmd			*prev;
};



//init
void	init();

//display
void	display();

//m_draw
void	draw_map2D();

//freerers

//lst_utils

//exit

#endif
