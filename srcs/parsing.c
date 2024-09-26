/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:16:50 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/26 13:44:26 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_color(char *line, t_game *game)
{
	if (line[0] == 'F')
		game->paths.f_color = ft_strdup(line + 2);
	if (line[0] == 'C')
		game->paths.c_color = ft_strdup(line + 2);
}

void	print_parsing(t_game *game)
{
	int	i;

	i = 0;
	printf("NO: %s\n", game->paths.no_path);
	printf("SO: %s\n", game->paths.so_path);
	printf("WE: %s\n", game->paths.we_path);
	printf("EA: %s\n", game->paths.ea_path);
	printf("F: %s\n", game->paths.f_color);
	printf("C: %s\n", game->paths.c_color);
	while (game->map[i] != NULL)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}

char	*ft_strdup_update(const char *s1)
{
	char	*strr;
	int		size;
	int		i;

	size = ft_strlen(s1);
	strr = malloc((size + 1) * sizeof(char));
	if (!strr)
		return (strr);
	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		strr[i] = s1[i];
		i++;
	}
	strr[i] = '\0';
	return (strr);
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
			game->paths.no_path = ft_strdup_update(line + 3);
		if (line[0] == 'S' && line[1] == 'O')
			game->paths.so_path = ft_strdup_update(line + 3);
		if (line[0] == 'W' && line[1] == 'E')
			game->paths.we_path = ft_strdup_update(line + 3);
		if (line[0] == 'E' && line[1] == 'A')
			game->paths.ea_path = ft_strdup_update(line + 3);
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
