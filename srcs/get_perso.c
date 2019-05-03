/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:46:04 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/03 19:03:13 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

int		check_pos2(int x, int y, t_map *map, t_perso *p)
{
	if (x < 0 || x >= TS * map->t_x || y < 0 || y >= TS * map->t_y)
		return (0);
	if (!is_touchable_wall(map->grid[y / TS][x / TS]))
		return (1);
	else if (find_height(map->grid[y / TS][x / TS]) * 2 - TS * 1.5 <= p->fh)
		return (1);
	return (0);
}

int		check_pos(int x, int y, t_map *map, t_perso *p)
{
	if (!(check_pos2(x, y, map, p)))
		return (0);
	if (!(check_pos2(x + TS / 100, y, map, p)))
		return (0);
	if (!(check_pos2(x, y + TS / 100, map, p)))
		return (0);
	if (!(check_pos2(x - TS / 100, y, map, p)))
		return (0);
	if (!(check_pos2(x, y - TS / 100, map, p)))
		return (0);
	return (1);
}

void	height_handler(t_perso *p, t_map *m)
{
	p->mv_h += (p->fh > GRAVITY * TS) ? -p->fh / TS : -GRAVITY;
	if (m->cur_bl == 's' && p->on_floor)
		p->mv_h = TS / 5;
	if (find_height(m->cur_bl) * 2 - TS > p->fh && p->mv_h < 0)
	{
		p->mv_h = 0;
		if (is_touchable_wall(m->cur_bl))
			p->fh = find_height(m->cur_bl) * 2 - TS - 0.1;
		if (!p->on_floor)
			p->vd = TS / 10;
		p->on_floor = 1;
	}
	else
		p->on_floor = 0;
	p->fh += p->mv_h;
	p->h = p->fh + p->hh;
}

void	get_perso(t_env *e, t_perso *p)
{
	float	x;
	float	y;

	p->angle += p->mv_r;
	if (p->angle >= 360 || p->angle < 0)
		p->angle = (p->angle < 0) ? 360 + p->angle : p->angle % 360;
	x = p->pos_x + sin((float)p->angle * CT) * p->vd * p->mv_y
		+ cos((float)p->angle * CT) * p->vd * p->mv_x;
	y = p->pos_y + cos((float)p->angle * CT) * p->vd * p->mv_y
		- sin((float)p->angle * CT) * p->vd * p->mv_x;
	if (check_pos((int)x, (int)y, e->map, p))
	{
		p->pos_x = x;
		p->pos_y = y;
	}
	else if (check_pos(p->pos_x, y, e->map, p))
		p->pos_y = y;
	else if (check_pos(x, p->pos_y, e->map, p))
		p->pos_x = x;
	find_block(e, p);
	height_handler(p, e->map);
	if (get_obj(e))
		e->map->grid[(int)p->pos_y / TS][(int)p->pos_x / TS] = 0;
}
