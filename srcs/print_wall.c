/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:14:04 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/27 17:18:35 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_view.h"

static uint32_t		print_ceiling(t_render r, t_column c, t_env *e)
{
	r.nz = e->run;
	if (!is_end_wall(c.num))
		return (XX);
	return (skybox(r, c, e));
}

uint32_t			print_floor(t_render r, t_column c, t_env *e)
{
	float	light;
	Uint8	sh;

	light = (((r.z - (e->win_y + e->pe->pos_z)) * (r.wall_light - 1))
			/ (r.wall_start - (e->win_y + e->pe->pos_z))) + 1;
	sh = 125;
	if (c.last_num < 'A' || c.last_num > 'Z')
		sh = (c.last_height) ? 50 : 125;
	sh *= light;
	return ((sh + (sh * 256) + (sh * 256 * 256)) | 0xff000000);
}

uint32_t			print_wall(t_render r, t_column c, t_env *e, char *tstr)
{
	if (r.wall_light <= 0.05)
		return (BLACK);
	r.nz = TS - 2 - (int)(((r.wall_end + c.h - r.z) * c.d_mur) / 779.4) % TS;
	r.nx = (int)((float)r.nx / TS * (float)e->t.text2->w);
	r.nz = (int)((float)r.nz / (float)TS * (float)e->t.text2->h);
	if (c.num == 't' && !(r.nz % (TS / 10) > TS / 20))
		return (XX);
	return (moon_wall(r, tstr));
}

uint32_t			render(t_render r, t_column c, t_env *e)
{
	if (r.z > r.wall_start)
		return (print_floor(r, c, e));
	else if (r.z < r.wall_end)
		return (print_ceiling(r, c, e));
	else
	{
		if (c.num == '1')
			return (print_wall(r, c, e, e->t.tstr0));
		if (c.num == '2')
			return (print_wall(r, c, e, e->t.tstr1));
		if (c.num == '3')
			return (print_wall(r, c, e, e->t.tstr2));
		if (c.num == '4' || c.num == '8')
			return (print_wall(r, c, e, e->t.tstr3));
		if (c.num == '5')
			return (print_wall(r, c, e, e->t.tstr4));
		if (c.num == '6' || c.num == 8)
			return (print_wall(r, c, e, e->t.tstr5));
		if ((c.num >= 'a' && c.num <= 'o') || c.num == 't')
			return (print_wall(r, c, e, e->t.tstr3));
		if (c.num == 'p')
			return (print_wall(r, c, e, e->t.tstr7));
		return (print_wall(r, c, e, e->t.tstr3));
	}
	return (0);
}
