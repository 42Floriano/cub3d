/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:44 by albertini         #+#    #+#             */
/*   Updated: 2024/08/22 16:26:48 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

 //the map array. Edit to change level but keep the outer walls

int map[] =
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,
};

void	draw_map2D()
{
// int	x;
// int	y;
// int	xo;
// int	yo;

//  y = 0;
//  while (y < MAPY)
//  {
// 	x = 0;
// 	while (x < MAPX)
// 	{
// 		if (map[y*MAPX+x]==1)
// 			glColor3f(1,1,1);
// 		else 
// 			glColor3f(0,0,0);
// 		xo=x*MAPS;
// 		yo=y*MAPS;
// 		glBegin(GL_QUADS); 
// 		glVertex2i( 0   +xo+1, 0   +yo+1);
// 		glVertex2i( 0   +xo+1, MAPS+yo-1);
// 		glVertex2i( MAPS+xo-1, MAPS+yo-1);
// 		glVertex2i( MAPS+xo-1, 0   +yo+1);
// 		glEnd();
// 		x++;
// 	}
// 	y++;
 }
