/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_search_impacts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:22:02 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/10 13:27:20 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"
#include "../include/raycast.h"

t_dist	init_search(t_ray r, t_column c)
{
	t_dist	d;

	d.xm = (int)(c.xi / TS + r.cfxa) * TS;
	d.ym = r.coef * d.xm + c.yi - r.coef * c.xi;
	d.ya = TS * tanf(r.a / 180 * M_PI);
	d.bm = (int)(c.yi / TS + r.cfya) * TS;
	d.am = (d.bm - (c.yi - r.coef * c.xi)) / r.coef;
	d.xa = TS / tanf(r.a / 180 * M_PI);
	return (d);
}
