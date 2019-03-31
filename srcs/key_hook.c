/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/27 16:50:21 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	key_moove(int k, t_env *e)
{
	e->pe->mv_y = (k == KW) ? 1 : e->pe->mv_y;
	e->pe->mv_y = (k == KS) ? -1 : e->pe->mv_y;
	e->pe->mv_x = (k == KD) ? -1 : e->pe->mv_x;
	e->pe->mv_x = (k == KA) ? 1 : e->pe->mv_x;
	e->pe->mv_r = (k == RIGHT) ? 1 : e->pe->mv_r;
	e->pe->mv_r = (k == LEFT) ? -1 : e->pe->mv_r;
	e->pe->mv_z = (k == DOWN) ? 5 : e->pe->mv_z;
	e->pe->mv_z = (k == UP) ? -5 : e->pe->mv_z;
}

int		key_press(int k, t_env *e)
{
	key_moove(k, e);

	if (e->o.flashlight == 1)
	{
		if (k == KL)
			e->t.lighton = (e->t.lighton) ? 0 : 1;
	}
	if (k == KF)
		e->f = (e->f) ? 0 : 1;
	if (k == KO)
		e->pe->h += 5;
	if (k == KL)
		e->pe->h -= 5;
	if (e->o.map == 1)
	{
		if (k == KM)
			e->pm = (e->pm) ? 0 : 1;
	}
	if (k == KP)
	{
		e->p = 0;
		e->psi = (e->psi) ? 0 : 1;
	}
	if (k == KE)
	{
		check_close_bl(e,e->pe);
	printf("clef = %d \n",e->o.key);
}
	if (k == KR)
		e->pe->vd = 10;
	if (k == KC)
		e->o.cible = (e->o.cible == 0) ? 1 : 0;
//	if (k == KT)
//		 next_lvl();
	expose_hook(e);
	return (0);
}

int		key_release(int k, t_env *e)
{
	if (k == KR)
		e->pe->vd = 3;
	if (k == ESC)
		ft_exit(3);
	if (k == KW || k == KS)
		e->pe->mv_y = 0;
	if (k == KD || k == KA)
		e->pe->mv_x = 0;
	if (k == LEFT || k == RIGHT)
		e->pe->mv_r = 0;
	if (k == UP || k == DOWN)
		e->pe->mv_z = 0;
	expose_hook(e);
	return (0);
}
