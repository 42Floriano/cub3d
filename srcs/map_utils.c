/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/19 14:20:24 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	make_it_rectangle(t_game *game, int max_size)
{
	int	i;
	int	j;

	i = 0;
	game->dup_map = (char **)malloc(sizeof(char *) * (game->array_size + 1));
	if (!game->dup_map)
		print_error("problem with malloc");
	while (game->map[i])
	{
		game->dup_map[i] = malloc(sizeof(char *) * (max_size + 1));
		j = 0;
		while (game->map[i][j])
		{
			game->dup_map[i][j] = game->map[i][j];
			if ((game->map[i][j] != '1' || game->map[i][j] != '0')
				&& j < max_size)
				game->dup_map[i][j] = 'S';
			j++;
		}
		game->dup_map[i][j] = '\0';
		i++;
	}
}

int	max_lenght(t_game *game)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (j > max)
				max = j;
			j++;
		}
		i++;
	}
	return (max);
}
