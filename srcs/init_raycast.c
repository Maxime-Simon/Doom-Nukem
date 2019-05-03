/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:07:20 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/30 18:54:55 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

t_ray	init_raycast(float d, t_env *e, t_column *c)
{
	t_ray	r;

	c->this_height = -1;
	c->last_height = find_height(
			e->map->grid[(int)e->pe->pos_y / TS][(int)e->pe->pos_x / TS]);
	c->nb_wall = 0;
	c->num = -1;
	c->last_num = -1;
	c->xi = -1;
	d = (!d) ? 0.1 : d;
	r.dd = d;
	r.coef = cosf(d / 180 * M_PI) / sinf(d / 180 * M_PI);
	r.a = (d < 180) ? 90 - d : 270 - d;
	r.a = (d > 270 || (d > 90 && d < 180)) ? -r.a : r.a;
	r.cfxa = (d < 180) ? 1 : 0;
	r.cfxb = (d < 180) ? 1 : -1;
	r.cfxc = (d < 90 || d > 270) ? 1 : -1;
	r.cfxd = (d < 180) ? 6 : 3;
	r.cfya = (d < 90 || d > 270) ? 1 : 0;
	r.cfyb = (d < 180) ? 1 : -1;
	r.cfyc = (d < 90 || d > 270) ? 1 : -1;
	r.cfyd = (d < 90 || d > 270) ? 6 : 4;
	return (r);
}
