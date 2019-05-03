/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:12:14 by madecreu          #+#    #+#             */
/*   Updated: 2019/05/02 20:07:22 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/edit.h"

void	pixel_put(char *pixels, int x, int y, int color)
{
	int		i;

	if (x < WE && y < HE && x >= 0 && y >= 0)
	{
		i = (x + y * WE) * 4;
		pixels[i] = color;
		pixels[i + 1] = color >> 8;
		pixels[i + 2] = color >> 16;
	}
}

t_map	fill_map(t_map map)
{
	int i;
	int c;

	i = 0;
	while (i < map.max_y)
	{
		c = 0;
		while (c < map.max_x)
		{
			map.map[i][c] = 0;
			c++;
		}
		i++;
	}
	return (map);
}

t_map	create_map(t_env *env, int w, int h)
{
	int		i;

	env->map.max_x = w;
	env->map.max_y = h;
	if ((env->map.map = (int**)malloc(sizeof(int*) * env->map.max_y)) == NULL)
		exit_doom(env, 3, "Malloc failed");
	i = 0;
	while (i < env->map.max_y)
	{
		if ((env->map.map[i] = (int*)malloc(sizeof(int)
			* env->map.max_x)) == NULL)
			exit_doom(env, 2, "Malloc failed");
		i++;
	}
	return (fill_map(env->map));
}

void	select_and_print(int value, int fd)
{
	if (value >= 0 && value <= 9 && value != 7)
		ft_putnbr_fd(value, fd);
	else if (value >= 10)
		ft_putchar_fd(value + 87, fd);
	else if (value == -1)
		ft_putchar_fd('F', fd);
	else if (value == -2)
		ft_putchar_fd('J', fd);
	else if (value == -3)
		ft_putchar_fd('K', fd);
	else if (value == -4)
		ft_putchar_fd('T', fd);
	else if (value == -5)
		ft_putchar_fd('M', fd);
	else if (value == -6)
		ft_putchar_fd('@', fd);
	else if (value == -7)
		ft_putchar_fd('p', fd);
	else if (value == -8)
		ft_putchar_fd('Z', fd);
	else if (value == 7)
		ft_putchar_fd('t', fd);
}
