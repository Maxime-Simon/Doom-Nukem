/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:34:18 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/22 17:21:38 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_view.h"

uint32_t	sky_wall0(t_render r, t_column c, t_env *e)
{
	Uint8		rgb[3];
	uint32_t	ret;

	r.nz = TS * 2 * e->map->t_x - 2
		- (int)(((r.wall_end + c.h - r.z) * c.d_mur) / 779.4);
	if (r.nz < 0)
		r.nz = 0;
	else
		r.nz = (int)((float)r.nz / (TS * 2 * e->map->t_x)
				* (float)e->t.text6->h);
	r.nx = (int)((float)c.xi / (TS * e->map->t_x) * (float)e->t.text6->w);
	rgb[2] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3];
	rgb[1] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 1];
	rgb[0] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 2];
	ret = rgb[2] + rgb[1] * 256 + rgb[0] * 256 * 256;
	return (ret | 0xff000000);
}

uint32_t	sky_wall1(t_render r, t_column c, t_env *e)
{
	Uint8		rgb[3];
	uint32_t	ret;

	r.nz = TS * 2 * e->map->t_x - 2
		- (int)(((r.wall_end + c.h - r.z) * c.d_mur) / 779.4);
	if (r.nz < 0)
		r.nz = 0;
	else
		r.nz = (int)((float)r.nz / (TS * 2 * e->map->t_x)
				* (float)e->t.text6->h);
	r.nx = (int)((float)c.yi / (TS * e->map->t_y) * (float)e->t.text6->w);
	rgb[2] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3];
	rgb[1] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 1];
	rgb[0] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 2];
	ret = rgb[2] + rgb[1] * 256 + rgb[0] * 256 * 256;
	return (ret | 0xff000000);
}

uint32_t	sky_wall2(t_render r, t_column c, t_env *e)
{
	Uint8		rgb[3];
	uint32_t	ret;

	r.nz = TS * 2 * e->map->t_x - 2
		- (int)(((r.wall_end + c.h - r.z) * c.d_mur) / 779.4);
	if (r.nz < 0)
		r.nz = 0;
	else
		r.nz = (int)((float)r.nz / (TS * 2 * e->map->t_x)
				* (float)e->t.text6->h);
	r.nx = (int)((float)c.xi / (TS * e->map->t_x) * (float)e->t.text6->w);
	rgb[2] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3];
	rgb[1] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 1];
	rgb[0] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 2];
	ret = rgb[2] + rgb[1] * 256 + rgb[0] * 256 * 256;
	return (ret | 0xff000000);
}

uint32_t	sky_wall3(t_render r, t_column c, t_env *e)
{
	Uint8		rgb[3];
	uint32_t	ret;

	r.nz = TS * 2 * e->map->t_x - 2
		- (int)(((r.wall_end + c.h - r.z) * c.d_mur) / 779.4);
	if (r.nz < 0)
		r.nz = 0;
	else
		r.nz = (int)((float)r.nz / (TS * 2 * e->map->t_x)
				* (float)e->t.text6->h);
	r.nx = (int)((float)c.yi / (TS * e->map->t_y) * (float)e->t.text6->w);
	rgb[2] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3];
	rgb[1] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 1];
	rgb[0] = e->t.tstr6[(r.nx * 3) + e->t.text6->w * r.nz * 3 + 2];
	ret = rgb[2] + rgb[1] * 256 + rgb[0] * 256 * 256;
	return (ret | 0xff000000);
}

uint32_t	skybox(t_render r, t_column c, t_env *e)
{
	if (c.face == 0)
		return (sky_wall0(r, c, e));
	else if (c.face == 1)
		return (sky_wall1(r, c, e));
	else if (c.face == 2)
		return (sky_wall2(r, c, e));
	else
		return (sky_wall3(r, c, e));
}
