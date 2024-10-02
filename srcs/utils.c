/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:59:09 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/02 15:35:04 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	data_init_bis(t_game *game)
{
	game->paths.no_path = NULL;
	game->paths.so_path = NULL;
	game->paths.we_path = NULL;
	game->paths.ea_path = NULL;
	game->map = NULL;
	game->paths.c_color = 0;
	game->paths.f_color = 0;
}
