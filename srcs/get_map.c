/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:19:06 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/29 16:37:34 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static int		line_handler(t_map *map, char *line)
{
	int	i;

	i = 0;
	if (!line || !line[0])
		return (0);
	map->t_x = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (!line[i])
		return (0);
	map->t_y = ft_atoi(&line[i]);
	if (map->t_x <= 0 || map->t_y <= 0 || map->t_x > 100 || map->t_y > 100)
		return (0);
	return (1);
}

static int		get_dim(t_map *map, int fd)
{
	char	*line;
	char	*temp;
	char	buff[2];

	line = NULL;
	buff[0] = '*';
	while (read(fd, buff, 1) > 0 && buff[0] != '\n' &&
	buff[0] != '\0' && ft_strlen(line) <= 10)
	{
		temp = line;
		buff[1] = '\0';
		if (!(line = ft_sbtlejoin(line, buff)))
			return (0);
		if (temp)
			free(temp);
	}
	if (buff[0] != '\n' || !(line_handler(map, line)))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

static int		recup_grid(t_map *map, int fd)
{
	int	i;

	i = 0;
	if (!(map->grid = (char **)malloc((map->t_y + 1) * sizeof(char *))))
		return (0);
	while (i < map->t_y)
	{
		if (!(map->grid[i] = (char *)malloc((map->t_x + 1) * sizeof(char))))
			return (0);
		if (read(fd, map->grid[i], map->t_x + 1) < map->t_x + 1)
			return (0);
		if (map->grid[i][map->t_x] != '\n')
			return (0);
		map->grid[i][map->t_x] = '\0';
		i++;
	}
	map->grid[i] = NULL;
	return (1);
}

int				get_map(t_map *map, int fd)
{
	if (!(get_dim(map, fd)))
		return (0);
	if (!(recup_grid(map, fd)))
		return (0);
	return (1);
}
