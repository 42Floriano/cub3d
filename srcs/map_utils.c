/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/26 12:51:36 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

// int	is_valid(t_game *game, char c)
// {
// 	if (c != ' ' || c != '1' || c != 0 || c != 'N' || c != 'S'
// 		|| c != 'W' || c != 'E')
// 		exit_error(game,
// 			"Map is not OK. Must have only ' ', 0, 1 or position's player.");
// 	return (0);
// }

void	make_it_rectangle(t_game *game, int max_size)
{
	int	i;
	int	j;

	i = 0;
	game->dup_map = safe_malloc(sizeof(char *) * (max_size + 1));
	while (game->map[i])
	{
		game->dup_map[i] = safe_malloc(sizeof(char) * (max_size + 2));
		j = 0;
		while (j < max_size)
		{
			if (j < (int)ft_strlen(game->map[i]) && game->dup_map[i][j] != '9')
				game->dup_map[i][j] = game->map[i][j];
			else
				game->dup_map[i][j] = '9';
			if (game->dup_map[i][j] != '1' && game->dup_map[i][j] != '0'
				&& !is_player(game->map[i][j])
					&& is_valid(game, game->dup_map[i][j]))
				game->dup_map[i][j] = '9';
			j++;
		}
		game->dup_map[i][j] = '\0';
		i++;
	}
	game->dup_map[i] = NULL;
}

int	max_lenght(t_game *game)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (j > max)
				max = j;
			j++;
		}
		i++;
	}
	return (max + 1);
}
