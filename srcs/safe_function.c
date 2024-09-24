/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:36:34 by aavduli           #+#    #+#             */
/*   Updated: 2024/09/24 14:16:57 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	safe_open(t_game *game, char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit_error(game, "Can't open the file !");
	}
	return (fd);
}
