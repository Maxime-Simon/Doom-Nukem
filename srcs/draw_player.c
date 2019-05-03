/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:37:45 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/24 17:10:07 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	erase_player(t_env *e, int y_map, int x_map)
{
	int	a;
	int b;

	a = (y_map > 5) ? y_map - 5 : 0;
	while (a <= e->map->img_y && a <= y_map + 5)
	{
		b = (x_map > 5) ? x_map - 5 : 0;
		while (b <= e->map->img_x && b <= x_map + 5)
		{
			if (e->map->data_map[a * e->map->img_x + b] == LBLUE)
				e->map->data_map[a * e->map->img_x + b] = LG4;
			b++;
		}
		a++;
	}
}

void	make_player(t_env *e)
{
	int	a;
	int b;
	int	y_map;
	int	x_map;

	e->pe->x_map = e->pe->pos_x * (float)e->map->img_x / (TS * e->map->t_x);
	e->pe->y_map = e->pe->pos_y * (float)e->map->img_y / (TS * e->map->t_y);
	x_map = e->pe->x_map;
	y_map = e->pe->y_map;
	a = (y_map > 5) ? y_map - 5 : 0;
	while (a <= e->map->img_y && a <= y_map + 5)
	{
		b = (x_map > 5) ? x_map - 5 : 0;
		while (b <= e->map->img_x && b <= x_map + 5)
		{
			if (e->map->data_map[a * e->map->img_x + b] == LG4)
				e->map->data_map[a * e->map->img_x + b] = LBLUE;
			b++;
		}
		a++;
	}
}
