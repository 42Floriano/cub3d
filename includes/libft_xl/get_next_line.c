/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:06 by albertini         #+#    #+#             */
/*   Updated: 2024/03/06 10:52:46 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char				*line;
	static t_list		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	read_and_stash(fd, &stash);
	extract_line(stash, &line);
	if (stash != NULL)
		clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

//Use read to add to the stash
void	read_and_stash(int fd, t_list **stash)
{
	char	*buff;
	int		rd;

	rd = 1;
	while (!found_nline(*stash) && rd != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		rd = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && rd == 0) || rd == -1)
		{
			free(buff);
			return ;
		}
		buff[rd] = '\0';
		add_to_stash(stash, buff, rd);
		free(buff);
	}
	return ;
}

//Add what is in the buffwer to the Stash
void	add_to_stash(t_list **stash, char *buff, int rd)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->content = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (new_node == NULL || new_node->content == NULL)
		return ;
	new_node->next = NULL;
	i = 0;
	while (buff[i] && i < rd)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

//Check the first \n in the stash and exctract the first line
void	extract_line(t_list *stash, char **line)
{
	t_list	*current;
	int		i;
	int		y;

	current = stash;
	*line = malloc(sizeof(char) * (get_size_line(stash) + 1));
	if (*line == NULL)
		return ;
	y = 0;
	while (current != NULL)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
			{
				(*line)[y++] = current->content[i];
				break ;
			}
			(*line)[y++] = current->content[i++];
		}
		current = current->next;
	}
	(*line)[y] = '\0';
}

//Clean the first line that we used in the Stash
void	clean_stash(t_list **stash)
{
	t_list	*l;
	t_list	*c;
	int		i;
	int		y;

	c = malloc(sizeof(t_list));
	if (c == NULL || *stash == NULL)
		return ;
	c->next = NULL;
	i = 0;
	l = ft_lst_get_last(*stash);
	while (l->content != NULL && l->content[i] && l->content[i] != '\n')
		i++;
	if (l->content && l->content[i] == '\n')
		i++;
	c->content = malloc(sizeof(char) * (ft_strlen(l->content) - i) + 1);
	if (c->content == NULL)
		return ;
	y = 0;
	while (l->content && l->content[i])
		c->content[y++] = l->content[i++];
	c->content[y] = '\0';
	free_stash(*stash);
	*stash = c;
}
