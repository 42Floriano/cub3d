/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:23:46 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/23 15:44:53 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid(t_game *game, char c, int i, int j)
{
	if (c == 'W' || c == 'S' || c == 'N' || c == 'E' )
	{
		game->player += 1;
		game->dup_map[i][j] = '0';
		if (game->player > 1)
			exit_error(game, "There should be only one player");
		return (1);
	}
	if (c == ' ' || c == '1' || c == '0' || c == '9')
		return (1);
	return (0);
}

void	make_it_rectangle(t_game *game, int max_size)
{
	int	i;
	int	j;

	i = 0;
	game->dup_map = safe_malloc(sizeof(char *) * (game->array_size + 1));
	while (game->map[i])
	{
		game->dup_map[i] = safe_malloc(sizeof(char) * (max_size + 1));
		j = 0;
		while (j < max_size)
		{
			if (j < (int)ft_strlen(game->map[i]))
				game->dup_map[i][j] = game->map[i][j];
			else
				game->dup_map[i][j] = '9';
			if (is_valid(game, game->dup_map[i][j], i, j)
				&& (game->dup_map[i][j] != '1' && game->dup_map[i][j] != '0'))
				game->dup_map[i][j] = '9';
			j++;
		}
		game->dup_map[i][j] = '\0';
		i++;
	}
	game->dup_map[i] = NULL;
	i = 0;
	while (game->dup_map[i])
	{
		printf("%s\n", game->dup_map[i]);
		i++;
	}
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
