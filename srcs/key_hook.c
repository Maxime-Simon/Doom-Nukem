/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/01 16:15:35 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static void		key_move(int k, t_env *e)
{
	e->pe->mv_y = (k == KW || k == UP) ? 1 : e->pe->mv_y;
	e->pe->mv_y = (k == KS || k == DOWN) ? -1 : e->pe->mv_y;
	e->pe->mv_x = (k == KD) ? -1 : e->pe->mv_x;
	e->pe->mv_x = (k == KA) ? 1 : e->pe->mv_x;
	e->pe->mv_r = (k == RIGHT) ? 1 : e->pe->mv_r;
	e->pe->mv_r = (k == LEFT) ? -1 : e->pe->mv_r;
}

static int		key_press2(int k, t_env *e)
{
	if (k == KM && e->o.map == 1)
		e->pm = (e->pm) ? 0 : 1;
	if (k == KR && e->pe->on_floor && e->pe->hh == TS)
		e->pe->vd = TS / 5;
	if (k == KB && e->pe->on_floor)
	{
		e->pe->hh = TS / 2;
		e->pe->vd = TS / 50;
	}
	if (k == KV && e->pe->on_floor)
	{
		e->pe->hh = TS / 4;
		e->pe->vd = TS / 60;
	}
	expose_hook(e);
	return (0);
}

int				key_press(int k, t_env *e)
{
	key_move(k, e);
	if (k == KE && e->o.key > 0)
		check_close_bl(e, e->pe);
	if (k == SPACE && (e->pe->on_floor || e->o.jetpack)
			&& e->pe->hh == TS)
		e->pe->mv_h += (e->pe->on_floor) ? TS / 10 : TS / 20;
	if (k == KL && e->o.offtorch == 1 && e->o.flint == 1 && e->o.lighton == 0)
	{
		e->o.lighton = 1;
		e->o.lightbar = 1;
		e->o.offtorch = 0;
		e->o.trc_end = SDL_GetTicks() + TIME_L;
	}
	key_press2(k, e);
	return (0);
}

int				key_release(int k, t_env *e)
{
	if ((k == KR || k == KB || k == KV) && e->pe->on_floor)
		e->pe->vd = TS / 10;
	if (k == ESC)
		ft_exit(3);
	if (k == KW || k == KS || k == UP || k == DOWN)
		e->pe->mv_y = 0;
	if (k == KD || k == KA)
		e->pe->mv_x = 0;
	if (k == LEFT || k == RIGHT)
		e->pe->mv_r = 0;
	if (k == KB || k == KV)
		e->pe->hh = TS;
	expose_hook(e);
	return (0);
}
