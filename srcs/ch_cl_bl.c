/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_cl_bl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxsimon <maxsimon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:30:12 by maxsimon          #+#    #+#             */
/*   Updated: 2019/05/04 13:55:09 by maxsimon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	check_close_bl2(t_env *e, t_perso *p)
{
	if (e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) - 1]
			&& e->o.key > 0)
	{
		if (e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) - 1] == 'p')
		{
			e->map->grid[((int)p->pos_y) / TS][((int)p->pos_x / TS) - 1] = '0';
			e->o.key--;
		}
	}
	if (e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) + 1]
			&& e->o.key > 0)
	{
		if (e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) + 1] == 'p')
		{
			e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) + 1] = '0';
			e->o.key--;
		}
	}
}

void	check_close_bl(t_env *e, t_perso *p)
{
	if (((int)p->pos_y / TS) - 1 >= 0)
	{
		if (e->map->grid[(int)p->pos_y / TS - 1][(int)p->pos_x / TS]
				&& e->o.key > 0)
		{
			if (e->map->grid[(int)p->pos_y / TS - 1][(int)p->pos_x / TS] == 'p')
			{
				e->map->grid[(int)p->pos_y / TS - 1][(int)p->pos_x / TS] = '0';
				e->o.key--;
			}
		}
		else if (e->map->grid[((int)p->pos_y / TS) + 1][(int)p->pos_x / TS]
				&& e->o.key > 0)
		{
			if (e->map->grid[(int)p->pos_y / TS + 1][(int)p->pos_x / TS] == 'p')
			{
				e->map->grid[(int)p->pos_y / TS + 1][(int)p->pos_x / TS] = '0';
				e->o.key--;
			}
		}
		check_close_bl2(e, p);
	}
}
