/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:43:05 by vapiatko          #+#    #+#             */
/*   Updated: 2019/05/03 15:24:44 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static void		end_level(t_env *e)
{
	SDL_ShowSimpleMessageBox(e->tx.sdl_flag, "End", e->tx.end, NULL);
	ft_exit(6);
}

static int		get_obj2(t_env *e)
{
	if (e->map->cur_bl == 'K')
	{
		e->o.key = 1;
		return (1);
	}
	if (e->map->cur_bl == 'J')
	{
		e->o.jetpack = 1;
		return (1);
	}
	if (e->map->cur_bl == 'Z')
	{
		end_level(e);
	}
	return (0);
}

int				get_obj(t_env *e)
{
	if (!e->pe->on_floor)
		return (0);
	if (e->map->cur_bl == 'T')
	{
		e->o.offtorch = 1;
		return (1);
	}
	if (e->map->cur_bl == 'F')
	{
		e->o.flint = 1;
		return (1);
	}
	if (e->map->cur_bl == 'M')
	{
		e->o.map = 1;
		e->pm = 1;
		return (1);
	}
	return (get_obj2(e));
}
