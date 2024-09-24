/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:34 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/19 14:54:35 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_vertical(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->dup_map[i][j])
	{
		i = 0;
		while (game->dup_map[i])
		{
			if ((game->dup_map[i][j] == '0') && game->dup_map[i - 1][j] == 'S'
				|| game->dup_map[i + 1][j] == 'S')
				return (0);
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
			if ((game->dup_map[i][j] == '0') && game->dup_map[i][j - 1] == 'S'
				|| game->dup_map[i][j + 1] == 'S')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	wall_e(t_game *game, int max_size)
{
	int	i;
	int	j;

	i = 0;
	while (game->dup_map[i])
	{
		while (j <= max_size)
		{
			if (game->dup_map[i][j] != 'S' || game->dup_map[i][j] != '1')
				return (0);
		}
	}
}

void	check_map(t_game *game)
{
	int	i;
	int	j;
	int	max_size;

	i = 0;
	max_size = max_lenght(game);
	make_it_rectangle(game, max_size);
	if (!validate_horizontal(game) || !validate_vertical(game))
		print_error("Map isn't valid ! Please do what necessary.");
}
