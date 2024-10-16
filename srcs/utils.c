/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:59:09 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/16 15:28:46 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parsing2(t_game *game, char *av)
{
	if (game->map)
		copy_map(game, av);
	else
	{
		printf("Error\nCan't find the map\n");
		exit_parsing(game);
	}
}

void	data_init_bis(t_game *game)
{
	game->paths.no_path = NULL;
	game->paths.so_path = NULL;
	game->paths.we_path = NULL;
	game->paths.ea_path = NULL;
	game->map = NULL;
	game->paths.c_color = -1;
	game->paths.f_color = -1;
}

int	check_params(t_game *game)
{
	if (game->paths.no_path == NULL)
		return (0);
	else if (game->paths.so_path == NULL)
		return (0);
	else if (game->paths.we_path == NULL)
		return (0);
	else if (game->paths.ea_path == NULL)
		return (0);
	else if (game->paths.f_color == -1)
		return (0);
	else if (game->paths.c_color == -1)
		return (0);
	return (1);
}

static int	check_line(char *line, int fd)
{
	while (line != NULL && line[0] != '1' && line[0] != '0')
	{
		if (ft_strncmp(line, "NO ", 3)
			&& ft_strncmp(line, "SO ", 3)
			&& ft_strncmp(line, "WE ", 3)
			&& ft_strncmp(line, "EA ", 3)
			&& ft_strncmp(line, "F ", 2)
			&& ft_strncmp(line, "C ", 2)
			&& line[0] != '\n'
			&& line[0] != ' ')
		{
			printf("Error\nThis is not valid : %s", line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

void	check_file(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = safe_open(game, file);
	line = get_next_line(fd);
	if (!check_line(line, fd))
		exit(1);
	while (line != NULL)
	{
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return ;
}
