/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:05:58 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/01 16:14:09 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static void		init_spr(t_env *e)
{
	e->o.spr_ct_flint = 0;
	e->o.spr_ct_map = 0;
	e->o.spr_ct_torch = 0;
	e->o.spr_ct_jetpack = 0;
	e->o.spr_ct_end = 0;
	e->o.spr_ct_key = 0;
}

int				expose_hook(t_env *e)
{
	if (e->pe->pos_x == -1)
	{
		e->map->surf_map = SDL_CreateRGBSurface(0, e->map->img_x, e->map->
				img_y, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
		e->map->data_map = (Uint32 *)e->map->surf_map->pixels;
		e->surf = SDL_CreateRGBSurface(0, e->win_x, e->win_y,
				32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
		e->data = (Uint32 *)e->surf->pixels;
		get_grid(e);
	}
	get_perso(e, e->pe);
	make_player(e);
	e->surf->pixels = e->data;
	SDL_BlitSurface(e->surf, NULL, e->init, NULL);
	init_spr(e);
	multi_thread(e);
	print_hud(e);
	if (e->o.trc_end <= SDL_GetTicks())
		e->o.lighton = 0;
	SDL_UpdateWindowSurface(e->win);
	erase_player(e, e->pe->y_map, e->pe->x_map);
	return (1);
}
