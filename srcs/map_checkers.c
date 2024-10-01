/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:34 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/01 17:04:20 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_vertical(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->dup_map[0][j])
	{
		i = 0;
		while (game->dup_map[i])
		{
			if (i == 0 && game->dup_map[i][j] == '0')
				return (0);
			if (game->dup_map[i][j] == '0')
			{
				if (game->dup_map[i - 1][j] == '9' ||
					(game->dup_map[i + 1] && game->dup_map[i + 1][j] == '9'))
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	validate_horizontal(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->dup_map[i])
	{
		j = 0;
		while (game->dup_map[i][j])
		{
			if (game->dup_map[i][j] == '0' && (game->dup_map[i][j - 1] == '9'
				|| game->dup_map[i][j + 1] == '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_game *game)
{
	int	max_size;

	max_size = max_lenght(game);
	make_it_rectangle(game, max_size);
	if (!validate_horizontal(game) || !validate_vertical(game))
		exit_error(game, "Map isn't valid, pls correct it.");
}
