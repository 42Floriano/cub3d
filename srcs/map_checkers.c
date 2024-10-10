/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:18:34 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/10 17:03:53 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	map_width(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}

int	valid_carac(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->dup_map[i])
	{
		j = 0;
		while (game->dup_map[i][j])
		{
			if (!is_valid(game, game->dup_map[i][j], i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

	if (!game->map)
	{
		printf("Error\n Where is you map boy ?!\n");
		exit_parsing(game);
	}
	max_size = max_lenght(game);
	make_it_rectangle(game, max_size);
	if (!validate_horizontal(game) || !validate_vertical(game)
		|| !valid_carac(game) || !check_params(game)
		|| game->player == 0)
	{
		free_array(game->map);
		free_array(game->dup_map);
		printf("Error\nPlease, check the file !\n");
		exit(EXIT_FAILURE);
	}
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = map_width(game);
	free_array(game->dup_map);
}
