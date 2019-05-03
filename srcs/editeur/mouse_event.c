/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:25:51 by madecreu          #+#    #+#             */
/*   Updated: 2019/04/26 16:59:15 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/edit.h"

void	mouse_motion(t_env *env)
{
	SDL_Event	ev;
	int			temp1;
	int			temp2;

	ev = env->sdl.event;
	temp1 = ev.motion.y / (HE / env->map.max_y);
	temp2 = ev.motion.x / (HE / env->map.max_x);
	if (env->edit.brush >= 0 && env->edit.edit == 1 && ev.motion.x < HE
		&& ev.motion.y < HE && ev.motion.x >= 0 && ev.motion.y >= 0)
		env->map.map[temp1][temp2] = env->edit.brush;
	else if (env->edit.brush < 0 && env->edit.edit == 1 && ev.motion.x < HE
		&& ev.motion.y < HE && ev.motion.x >= 0 && ev.motion.y >= 0)
		replace_item(env, ev.motion.x, ev.motion.y);
}

void	mouse_release(t_env *env)
{
	env->edit.edit = 0;
}

void	mouse_press3(t_env *env, int x, int y)
{
	if (x >= 1550 && x <= 1600 && y >= 700 && y <= 750)
		env->edit.brush = 13;
	else if (x >= 1650 && x <= 1700 && y >= 700 && y <= 750)
		env->edit.brush = 14;
	else if (x >= 1750 && x <= 1800 && y >= 700 && y <= 750)
		env->edit.brush = 15;
	else if (x >= 1850 && x <= 1900 && y >= 700 && y <= 750)
		env->edit.brush = 16;
	else if (x >= 1700 && x <= 1750 && y >= 500 && y <= 550)
		env->edit.brush = 7;
	else if (x >= 1400 && x <= 1800 && y >= 1000 && y <= 1150)
		save_and_exit(env);
}

void	mouse_press2(t_env *env, int x, int y)
{
	if (x >= 1425 && x <= 1475 && y >= 300 && y <= 350)
		env->edit.brush = -2;
	else if (x >= 1550 && x <= 1600 && y >= 300 && y <= 350)
		env->edit.brush = -3;
	else if (x >= 1675 && x <= 1725 && y >= 300 && y <= 350)
		env->edit.brush = -4;
	else if (x >= 1800 && x <= 1850 && y >= 300 && y <= 350)
		env->edit.brush = -5;
	else if (x >= 1300 && x <= 1350 && y >= 500 && y <= 550)
		env->edit.brush = -6;
	else if (x >= 1400 && x <= 1450 && y >= 500 && y <= 550)
		env->edit.brush = 9;
	else if (x >= 1500 && x <= 1550 && y >= 500 && y <= 550)
		env->edit.brush = -7;
	else if (x >= 1600 && x <= 1650 && y >= 500 && y <= 550)
		env->edit.brush = 8;
	else if (x >= 1800 && x <= 1850 && y >= 500 && y <= 550)
		env->edit.brush = -8;
	else if (x >= 1250 && x <= 1300 && y >= 700 && y <= 750)
		env->edit.brush = 10;
	else if (x >= 1350 && x <= 1400 && y >= 700 && y <= 750)
		env->edit.brush = 11;
	else if (x >= 1450 && x <= 1500 && y >= 700 && y <= 750)
		env->edit.brush = 12;
	mouse_press3(env, x, y);
}

void	mouse_press(t_env *env)
{
	SDL_Event	ev;
	int			x;
	int			y;

	ev = env->sdl.event;
	env->edit.edit = 1;
	x = ev.button.x;
	y = ev.button.y;
	if (x >= 1250 && x <= 1300 && y >= 100 && y <= 150)
		env->edit.brush = 0;
	else if (x >= 1350 && x <= 1400 && y >= 100 && y <= 150)
		env->edit.brush = 1;
	else if (x >= 1450 && x <= 1500 && y >= 100 && y <= 150)
		env->edit.brush = 2;
	else if (x >= 1550 && x <= 1600 && y >= 100 && y <= 150)
		env->edit.brush = 3;
	else if (x >= 1650 && x <= 1700 && y >= 100 && y <= 150)
		env->edit.brush = 4;
	else if (x >= 1750 && x <= 1800 && y >= 100 && y <= 150)
		env->edit.brush = 5;
	else if (x >= 1850 && x <= 1900 && y >= 100 && y <= 150)
		env->edit.brush = 6;
	else if (x >= 1300 && x <= 1350 && y >= 300 && y <= 350)
		env->edit.brush = -1;
	mouse_press2(env, x, y);
}
