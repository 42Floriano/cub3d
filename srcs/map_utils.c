/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/24 15:53:49 by aavduli          ###   ########.fr       */
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

void	make_it_rectangle(t_game *game, int max_size)
{
	int	i;
	int	j;

	i = 0;
	game->dup_map = (char **)malloc(sizeof(char *) * (game->array_size + 1));
	if (!game->dup_map)
		exit_error(game, "problem with malloc.");
	while (game->map[i])
	{
		game->dup_map[i] = malloc(sizeof(char) * (max_size + 2));
		j = 0;
		while (j < max_size)
		{
			if (j < (int)ft_strlen(game->map[i]) && game->dup_map[i][j] != 'S')
				game->dup_map[i][j] = game->map[i][j];
			else
				game->dup_map[i][j] = 'S';
			if (game->dup_map[i][j] != '1' && game->dup_map[i][j] != '0' && !is_player(game->map[i][j]))
				game->dup_map[i][j] = 'S';
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
