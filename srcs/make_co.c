/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_co.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:52:27 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/03 19:02:51 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_view.h"

static void			check_sprite(t_env *e, char ch)
{
	if (ch == 'M' && e->o.spr_ct_map == 0)
		e->o.spr_ct_map = 1;
	if (ch == 'F' && e->o.spr_ct_flint == 0)
		e->o.spr_ct_flint = 1;
	if (ch == 'T' && e->o.spr_ct_torch == 0)
		e->o.spr_ct_torch = 1;
	if (ch == 'J' && e->o.spr_ct_jetpack == 0)
		e->o.spr_ct_jetpack = 1;
	if (ch == 'K' && e->o.spr_ct_key == 0)
		e->o.spr_ct_key = 1;
	if (ch == 'Z' && e->o.spr_ct_end == 0)
		e->o.spr_ct_end = 1;
}

static t_render		init_render(t_column c, t_env *e)
{
	t_render	r;
	int			deb;

	r.z = e->pe->pos_z;
	if (c.this_height == 2)
		c.h = -1;
	r.nx = (c.face % 2) ? (int)c.yi % TS : (int)c.xi % TS;
	r.nx = (c.face == 1 || c.face == 2) ? TS - r.nx - 1 : r.nx;
	deb = (e->win_y + 779.4 * (TS + e->pe->h) / c.d_mur) / 2;
	r.wall_start = deb - (779.4 * c.last_height) / c.d_mur;
	r.wall_end = deb - c.h;
	if (e->o.lighton)
		r.wall_light = (c.d_mur > TS) ? 1 / (c.d_mur / TS) : 1;
	else
		r.wall_light = (c.d_mur > TS) ? 1 / (4 * c.d_mur / TS) : 0.25;
	return (r);
}

void				make_co(int i, t_env *e, t_column c)
{
	t_render r;

	i = e->win_x - i;
	c.last_height = (c.last_height == TS - 1) ? 0 : c.last_height;
	r = init_render(c, e);
	if (((c.num >= 'A' && c.num <= 'Z') || c.num == 'Z')
			&& r.nx % TS > 550 && r.nx % TS < 570 && c.nb_wall == 0)
	{
		e->o.spr_posx = i;
		e->o.spr_posy = 128 / (c.d_mur / TS);
		e->o.wich_spr = c.num;
		if (e->pe->hh == TS && e->pe->on_floor && e->pe->h <= TS
				&& SDL_LockMutex(e->mutex) == 0)
			print_sprites(e);
		check_sprite(e, c.num);
	}
	while (r.z < e->win_y + e->pe->pos_z)
	{
		if ((!c.nb_wall && c.last_num == -1)
				|| e->data[i + e->win_x * (r.z - e->pe->pos_z)] == XX)
			e->data[i + e->win_x * (r.z - e->pe->pos_z)] = render(r, c, e);
		r.z++;
	}
}
