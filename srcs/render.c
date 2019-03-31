/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:31:19 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/28 18:04:22 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

float		set_light_fc(t_env *e, int z)
{
	float lfc;

	lfc = 0;
	if (z <= 225)
		lfc = 1;
	else if (z > 225 && z <= 279)
		lfc = 0.75;
	else if (z > 279 && z <= 295)
		lfc = 0.5;
	else if (z > 295 && z <= 301)
		lfc = 0.25;
	else if (z > 301)
		lfc = 0;
	if (z >= e->win_y - 226)
		lfc = 1;
	else if (z < e->win_y - 226 && z >= e->win_y - 279)
		lfc = 0.75;
	else if (z < e->win_y - 279 && z >= e->win_y - 295)
		lfc = 0.5;
	else if (z < e->win_y - 295 && z >= e->win_y - 301)
		lfc = 0.25;
	else if (z > e->win_y - 301)
		lfc = 0;
	return (lfc);
}

float		set_light_tex(t_column *c)
{
	float ltex;

	ltex = 1;
	if (c->d_mur > 200)
		ltex = 200 / c->d_mur;
	return (ltex);
}

uint32_t	render(t_render r, int h, t_column c, t_env *e)
{
	float	ltex;
	float	lfc;
	int		ret;
	Uint8	rgb[3];

	ltex = (e->t.lighton == 1) ? set_light_tex(&c) : 0.25;
	lfc = (e->t.lighton == 1) ? set_light_fc(e, r.z) : 0.25;
	ret = 0;
	if (r.z >= (e->win_y + h) / 2)
		return (set_color(100 * lfc, 80 * lfc, 60 * lfc));
	else if (r.z <= (e->win_y - h) / 2)
		return (set_color(80 * lfc, 80 * lfc, 80 * lfc));
	else
	{
		if (c.face == 0)
		{
			r.nx = (int)((float)r.nx / TS * (float)e->t.text0->w);
			r.nz = (int)((float)r.nz / (float)TS * (float)e->t.text0->h);
			rgb[0] = e->t.tstr0[(r.nx * 3) + e->t.text0->w * r.nz * 3];
			rgb[1] = e->t.tstr0[(r.nx * 3) + e->t.text0->w * r.nz * 3 + 1];
			rgb[2] = e->t.tstr0[(r.nx * 3) + e->t.text0->w * r.nz * 3 + 2];
		}
		else if (c.face == 1)
		{
			r.ny = (int)((float)(TS - r.ny) / TS * (float)e->t.text1->w);
			r.nz = (int)((float)r.nz / (float)TS * (float)e->t.text1->h);
			rgb[0] = e->t.tstr1[(r.ny * 3) + e->t.text1->w * r.nz * 3];
			rgb[1] = e->t.tstr1[(r.ny * 3) + e->t.text1->w * r.nz * 3 + 1];
			rgb[2] = e->t.tstr1[(r.ny * 3) + e->t.text1->w * r.nz * 3 + 2];
		}
		else if (c.face == 2)
		{
			r.nx = (int)((float)(TS - r.nx) / TS * (float)e->t.text2->w);
			r.nz = (int)((float)r.nz / (float)TS * (float)e->t.text2->h);
			rgb[0] = e->t.tstr2[(r.nx * 3) + e->t.text2->w * r.nz * 3];
			rgb[1] = e->t.tstr2[(r.nx * 3) + e->t.text2->w * r.nz * 3 + 1];
			rgb[2] = e->t.tstr2[(r.nx * 3) + e->t.text2->w * r.nz * 3 + 2];
		}
		else if (c.face == 3)
		{
			r.ny = (int)((float)r.ny / TS * (float)e->t.text3->w);
			r.nz = (int)((float)r.nz / (float)TS * (float)e->t.text3->h);
			rgb[0] = e->t.tstr3[(r.ny * 3) + e->t.text3->w * r.nz * 3];
			rgb[1] = e->t.tstr3[(r.ny * 3) + e->t.text3->w * r.nz * 3 + 1];
			rgb[2] = e->t.tstr3[(r.ny * 3) + e->t.text3->w * r.nz * 3 + 2];
		}
		rgb[2] = (int)((float)rgb[2] * ltex);
		rgb[1] = (int)((float)rgb[1] * ltex);
		rgb[0] = (int)((float)rgb[0] * ltex);
		ret = rgb[2] + rgb[1] * 256 + rgb[0] * 256 * 256;
	}
	return (ret);
}
