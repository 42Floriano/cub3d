/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:47 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/01 17:31:15 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	malloc_mapy(t_game *game, char *line, int fd)
{
	char	*join;

	join = ft_strdup("");
	if (!join)
		exit_error(game, "Memory allocation failed for join");
	while (line != NULL)
	{
		join = ft_strjoin(join, line);
		free(line);
		if (!join)
			exit_error(game, "Memory allocation failed during strjoin");
		line = get_next_line(fd);
	}
	game->map = ft_split(join, '\n');
	if (!game->map)
		exit_error(game, "Memory allocation failed for game->map");
}

// void	clean_map(t_game *game)
// {
// 	char	*buf;
// 	int		len;

// 	buf = ft_strdup("");
// 	len = 0;
// 	while (game->map[len] != NULL)
// 	{
// 		buf = ft_strjoin(buf, game->map[len]);
// 		len++;
// 	}
// 	game->map = ft_split(buf, '\n');
// 	free(buf);
// }

// void	copy_map(t_game *game, char *av)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	i = 0;
// 	fd = safe_open(game, av);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if (line[0] == ' ' || line[0] == '1'
// 			|| line[0] == '0' || line[0] == '\t')
// 			break ;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	while (line != NULL)
// 	{
// 		game->map[i] = ft_strdup(line);
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	game->map[i] = NULL;
// 	close(fd);
// 	free(line);
// 	clean_map(game);
// }
