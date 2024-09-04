/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:10:49 by albertini         #+#    #+#             */
/*   Updated: 2024/09/04 13:45:34 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**readmap(char *filename)
{
	int		fd;
	char	*buff;
	char	*line;
	char	*line_holder;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_holder = ft_strdup("");
	while (1)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		line = line_holder;
		line_holder = ft_strjoin(line, buff);
		free(line);
		free(buff);
	}
	map = ft_split(line_holder, '\n');
	free(line_holder);
	close(fd);
	return (map);
}
