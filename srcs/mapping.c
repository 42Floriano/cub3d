/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:47 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/03 13:22:16 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_map(char *line, t_game *game, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(line);
	while (line != NULL)
	{
		tmp = ft_strjoin(tmp, line);
		tmp = ft_strjoin(tmp, "\n");
		line = get_next_line(fd);
	}
	game->map->map = ft_split(tmp, '\n');
	while (game->map->map[i])
	{
		printf("%s\n", game->map->map[i]);
		i++;
	}
	free(tmp);
}
