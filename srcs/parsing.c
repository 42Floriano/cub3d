/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:16:50 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/17 11:41:09 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_color(char *line, t_game *game)
{
	if (line[0] == 'F')
		game->texture.f_color = ft_strdup(line + 2);
	if (line[0] == 'C')
		game->texture.c_color = ft_strdup(line + 2);
}

void	print_parsing(t_game *game)
{
	int	i;

	i = 0;
	printf("NO: %s\n", game->texture.no_path);
	printf("SO: %s\n", game->texture.so_path);
	printf("WE: %s\n", game->texture.we_path);
	printf("EA: %s\n", game->texture.ea_path);
	printf("F: %s\n", game->texture.f_color);
	printf("C: %s\n", game->texture.c_color);
	while (game->map.map[i] != NULL)
	{
		printf("%s\n", game->map.map[i]);
		i++;
	}
}

void	init_parsing(char *av, t_game *game)
{
	int		fd;
	char	*line;

	fd = safe_open(av);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == 'N' && line[1] == 'O')
			game->texture.no_path = ft_strdup(line + 3);
		if (line[0] == 'S' && line[1] == 'O')
			game->texture.so_path = ft_strdup(line + 3);
		if (line[0] == 'W' && line[1] == 'E')
			game->texture.we_path = ft_strdup(line + 3);
		if (line[0] == 'E' && line[1] == 'A')
			game->texture.ea_path = ft_strdup(line + 3);
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
	print_parsing(game);
}
