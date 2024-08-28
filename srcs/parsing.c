/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:16:50 by aavduli           #+#    #+#             */
/*   Updated: 2024/08/28 13:51:49 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_parsing(char *av, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'N')
			game->texture->no_path = ft_strdup(line + 2);
		else if (line[0] == 'S' && line[1] == 'O')
			game->texture->so_path = ft_strdup(line + 2);
		else if (line[0] == 'W' && line[1] == 'E')
			game->texture->we_path = ft_strdup(line + 2);
		else if (line[0] == 'E' && line[1] == 'A')
			game->texture->ea_path = ft_strdup(line + 2);
		if (line[0] == 'F' || line[0] == 'C')
			set_color(line, game);
		else if (line[0] == '1')
			set_map(line, game);
	}
}
