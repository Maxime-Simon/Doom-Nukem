/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:06:27 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/01 14:24:05 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"
#include "../include/raycast.h"

static int		is_wall(float x, float y, t_map *m, int f)
{
	int	mx;
	int	my;

	mx = (int)x / TS - f % 2;
	my = (int)y / TS - f % 3;
	if (mx < 0 || mx >= m->t_x || my < 0 || my >= m->t_y
		|| is_visible_wall(m->grid[my][mx]))
	{
		if (mx < 0 || mx >= m->t_x || my < 0 || my >= m->t_y)
			return ('E');
		else
			return (m->grid[my][mx]);
	}
	return (0);
}

static void		get_all(t_column *c, t_dist d, t_ray r)
{
	if (r.dx < r.dy)
	{
		c->d_mur = r.dx;
		c->num = d.tx;
		c->face = (r.dd < 180) ? 1 : 3;
		c->xi = d.xm;
		c->yi = d.ym;
	}
	else
	{
		c->d_mur = r.dy;
		c->num = d.ty;
		c->face = (r.dd < 90 || r.dd > 270) ? 0 : 2;
		c->xi = d.am;
		c->yi = d.bm;
	}
	c->this_height = find_height(c->num);
}

static void		find_d(t_ray r, t_map *m, t_column *c, t_perso *p)
{
	t_dist	d;
	int		temp;

	d = init_search(r, *c);
	temp = c->last_height;
	while (find_height(d.tx = is_wall(d.xm, d.ym, m, r.cfxd)) == temp
			&& !is_end_wall(d.tx))
	{
		d.xm += r.cfxb * TS;
		d.ym += r.cfxc * d.ya;
		temp = find_height(d.tx);
	}
	r.dx = hypotf((float)(p->pos_x) - d.xm, (float)(p->pos_y) - d.ym);
	temp = c->last_height;
	while (find_height(d.ty = is_wall(d.am, d.bm, m, r.cfyd)) == temp
			&& !is_end_wall(d.ty))
	{
		d.am += r.cfyb * d.xa;
		d.bm += r.cfyc * TS;
		temp = find_height(d.ty);
	}
	r.dy = hypotf((float)(p->pos_x) - d.am, (float)(p->pos_y) - d.bm);
	get_all(c, d, r);
}

void			raycast(t_ray r, t_perso *p, t_map *m, t_column *c)
{
	if (c->xi == -1)
	{
		c->xi = p->pos_x;
		c->yi = p->pos_y;
	}
	find_d(r, m, c, p);
}
