/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:59:09 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/16 12:50:59 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parsing2(t_game *game, char *av)
{
	if (game->map)
		copy_map(game, av);
	else
	{
		printf("Error\nCan't find the map\n");
		exit_parsing(game);
	}
}

void	data_init_bis(t_game *game)
{
	game->paths.no_path = NULL;
	game->paths.so_path = NULL;
	game->paths.we_path = NULL;
	game->paths.ea_path = NULL;
	game->map = NULL;
	game->paths.c_color = -1;
	game->paths.f_color = -1;
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
	else if (game->paths.f_color == -1)
		return (0);
	else if (game->paths.c_color == -1)
		return (0);
	return (1);
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return ;
}
