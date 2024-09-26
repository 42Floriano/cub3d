/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:16:50 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/26 12:54:52 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_color(char *line, t_game *game)
{
	if (line[0] == 'F')
		game->path.f_color = ft_strdup(line + 2);
	if (line[0] == 'C')
		game->path.c_color = ft_strdup(line + 2);
}

void	print_parsing(t_game *game)
{
	int	i;

	i = 0;
	printf("NO: %s\n", game->path.no_path);
	printf("SO: %s\n", game->path.so_path);
	printf("WE: %s\n", game->path.we_path);
	printf("EA: %s\n", game->path.ea_path);
	printf("F: %s\n", game->path.f_color);
	printf("C: %s\n", game->path.c_color);
	while (game->map[i] != NULL)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}

void	init_parsing(char *av, t_game *game)
{
	int		fd;
	char	*line;

	fd = safe_open(game, av);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == 'N' && line[1] == 'O')
			game->path.no_path = ft_strdup(line + 3);
		if (line[0] == 'S' && line[1] == 'O')
			game->path.so_path = ft_strdup(line + 3);
		if (line[0] == 'W' && line[1] == 'E')
			game->path.we_path = ft_strdup(line + 3);
		if (line[0] == 'E' && line[1] == 'A')
			game->path.ea_path = ft_strdup(line + 3);
		if (line[0] == 'F' || line[0] == 'C')
			set_color(line, game);
		if (line[0] == ' ' || line[0] == '1'
			|| line[0] == '0' || line[0] == '\t')
			malloc_mapy(game, line, fd);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	copy_map(game, av);
}
