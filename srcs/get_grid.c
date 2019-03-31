/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:58:12 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/27 16:50:17 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

int		get_color(char c, t_env *e, int i, int j)
{
	if (c == '@' && e->pe->pos_x < 0)
	{
		e->pe->pos_x = j * TS + TS / 2;
		e->pe->pos_y = i * TS + TS / 2;
		return (G4);
	}
	if (c == '0' || c == '@')
		return (G4);
	else if (c == '1' || c == '4')
		return (G1);
	else if (c == '2')
		return (G2);
	else if (c == '3')
		return (G3);
	else
		return (G4);
}

void	make_line(t_env *e)
{
	int	a;
	int	b;
	int height;

	height = e->map->img_y / e->map->t_y;
	a = 0;
	while (a <= e->map->img_y)
	{
		b = 0;
		while (b <= e->map->img_x)
		{
			e->map->data_map[a * e->map->img_x + b] = BLACK | 0xf0000000;
			b++;
		}
		a = a + height;
	}
}

void	make_column(t_env *e)
{
	int	a;
	int	b;
	int	width;

	width = e->map->img_x / e->map->t_x;
	b = 0;
	while (b <= e->map->img_x)
	{
		a = 0;
		while (a <= e->map->img_y)
		{
			e->map->data_map[a * e->map->img_x + b] = BLACK | 0xf0000000;
			a++;
		}
		b = b + width;
	}
}

void	make_rectangle(int i, int j, t_env *e)
{
	int	a;
	int	b;
	int	width;
	int height;
	int	color;

	color = get_color(e->map->grid[i][j], e, i, j);
	height = e->map->img_y / e->map->t_y;
	width = e->map->img_x / e->map->t_x;
	a = i * height;
	while (a < (i + 1) * height)
	{
		b = j * width;
		while (b < (j + 1) * width)
		{
			e->map->data_map[a * e->map->img_x + b] = color | 0xf0000000;
			b++;
		}
		a++;
	}
}

void	get_grid(t_env *e)
{
	int i;
	int	j;

	i = 0;
	while (i < e->map->t_y)
	{
		j = 0;
		while (j < e->map->t_x)
		{
			make_rectangle(i, j, e);
			j++;
		}
		i++;
	}
	make_line(e);
	make_column(e);
}
