/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:05:58 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/27 18:27:05 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

int		expose_hook(t_env *e)
{
	if (e->psi)
		e->p = (e->p + 3) % 256;
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
	get_view(e);
	e->surf->pixels = e->data;
	SDL_BlitSurface(e->surf, NULL, e->init, NULL);
	print_hud(e);
	SDL_UpdateWindowSurface(e->win);
	erase_player(e, e->pe->y_map, e->pe->x_map);
	return (1);
}
