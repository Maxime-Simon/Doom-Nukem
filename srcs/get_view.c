/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:56:21 by vapiatko          #+#    #+#             */
/*   Updated: 2019/05/03 19:06:12 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_view.h"

static void			edit_co(t_column *c)
{
	c->nb_wall++;
	c->last_num = c->num;
	c->last_height = c->this_height;
}

static float		find_a_ray(float p_angle, float i, float win_width)
{
	float	a_ray;

	a_ray = p_angle - 30 + i * 60 / win_width;
	a_ray = (a_ray < 0) ? 360 + a_ray : a_ray;
	a_ray = (a_ray >= 360) ? a_ray - 360 : a_ray;
	return (a_ray);
}

int					get_view(void *v)
{
	int			i[2];
	t_column	c;
	t_ray		r;
	float		d;
	t_env		*e;

	e = (t_env *)v;
	i[1] = e->deb++;
	i[0] = i[1] * (e->win_x / NB_THREAD);
	while (i[0] <= (i[1] + 1) * (e->win_x / NB_THREAD))
	{
		r.dd = find_a_ray((float)e->pe->angle, (float)i[0], (float)e->win_x);
		d = fabs(r.dd - (float)e->pe->angle);
		r = init_raycast(r.dd, e, &c);
		while (!is_end_wall(c.num) && c.nb_wall < 100)
		{
			raycast(r, e->pe, e->map, &c);
			c.d_mur = c.d_mur * cosf(d * CT);
			c.h = (779.4 * c.this_height) / c.d_mur;
			make_co(i[0], e, c);
			edit_co(&c);
		}
		i[0]++;
	}
	return (0);
}
