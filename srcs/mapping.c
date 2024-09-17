/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:47 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/17 13:32:00 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	malloc_mapy(t_game *game, char *line, int fd)
{
	int		count;

	count = 0;
	while (line != NULL)
	{
		count++;
		line = get_next_line(fd);
	}
	game->map = (char **)malloc(sizeof(char *) * count);
	if (game->map == NULL)
	{
		perror("Error\n");
		exit(1);
	}
}

void	clean_map(t_game *game)
{
	char	*buf;
	int		len;

	buf = ft_strdup("");
	len = 0;
	while (game->map[len] != NULL)
	{
		buf = ft_strjoin(buf, game->map[len]);
		free(game->map[len]);
		len++;
	}
	free(game->map);
	game->map = ft_split(buf, '\n');
	free(buf);
}

void	copy_map(t_game *game, char *av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = safe_open(av);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == ' ' || line[0] == '1'
			|| line[0] == '0' || line[0] == '\t')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		game->map[i] = ft_strdup(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	clean_map(game);
}
