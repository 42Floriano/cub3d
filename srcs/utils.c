/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:59:09 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/02 16:06:21 by aavduli          ###   ########.fr       */
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

int	check_params(t_game *game)
{
	if (game->paths.no_path == NULL)
		return (0);
	else if (game->paths.so_path == NULL)
		return (0);
	else if (game->paths.we_path == NULL)
		return (0);
	else if (game->paths.ea_path == NULL)
		return (0);
	else if (game->paths.f_color == 0)
		return (0);
	else if (game->paths.c_color == 0)
		return (0);
	return (1);
}
