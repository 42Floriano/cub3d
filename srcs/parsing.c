/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:47 by aavduli           #+#    #+#             */
/*   Updated: 2024/10/01 17:02:35 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			while (tab[i][j] == ' ')
				j++;
			if (tab[i][j] == '\n')
			{
				tab[i][j] = '\0';
				break ;
			}
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_valid(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (0);
	return (1);
}

static int	rgb_to_hex(int red, int green, int blue)
{
	if (red < 0)
		red = 0;
	if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

static void	set_color(char *line, t_game *game)
{
	char	**tab;

	if (line[0] == 'F' || line[0] == 'C')
	{
		tab = ft_split((line + 2), ',');
		if (!check_if_valid(tab) || !is_digit(tab))
		{
			free_array(tab);
			exit_error(game, "Please set valid RGB colors");
		}
		if (line[0] == 'F')
			game->paths.f_color = rgb_to_hex(ft_atoi(tab[0]),
					ft_atoi(tab[1]), ft_atoi(tab[2]));
		else
			game->paths.c_color = rgb_to_hex(ft_atoi(tab[0]),
					ft_atoi(tab[1]), ft_atoi(tab[2]));
		free_array(tab);
	}
}

static char	*ft_strdup_update(const char *s1)
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
		else if (line[0] == 'S' && line[1] == 'O')
			game->paths.so_path = ft_strdup_update(line + 3);
		else if (line[0] == 'W' && line[1] == 'E')
			game->paths.we_path = ft_strdup_update(line + 3);
		else if (line[0] == 'E' && line[1] == 'A')
			game->paths.ea_path = ft_strdup_update(line + 3);
		else if (line[0] == 'F' || line[0] == 'C')
			set_color(line, game);
		else if (line[0] == ' ' || line[0] == '1'
			|| line[0] == '0' || line[0] == '\t')
			malloc_mapy(game, line, fd);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	copy_map(game, av);
}
