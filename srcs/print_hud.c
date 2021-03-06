/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:25:07 by vapiatko          #+#    #+#             */
/*   Updated: 2019/04/21 15:58:13 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static void		print_obj_map(t_env *e)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 64;
	srcrect.h = 64;
	dstrect.x = e->win_x - 84;
	dstrect.y = 188;
	dstrect.w = 64;
	dstrect.h = 64;
	SDL_BlitSurface(e->o.map_tex, &srcrect, e->init, &dstrect);
}

static void		print_obj_key(t_env *e)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 64;
	srcrect.h = 64;
	dstrect.x = e->win_x - 84;
	dstrect.y = e->win_y - 84;
	dstrect.w = 64;
	dstrect.h = 64;
	SDL_BlitSurface(e->o.key_tex, &srcrect, e->init, &dstrect);
}

static void		print_jetpack(t_env *e)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 64;
	srcrect.h = 64;
	dstrect.x = e->win_x - 84;
	dstrect.y = 272;
	dstrect.w = 64;
	dstrect.h = 64;
	SDL_BlitSurface(e->o.jpk_tex, &srcrect, e->init, &dstrect);
}

void			print_hud(t_env *e)
{
	print_torch(e);
	if (e->pm)
		SDL_BlitSurface(e->map->surf_map, NULL, e->init, NULL);
	if (e->o.map == 1)
		print_obj_map(e);
	if (e->o.key == 1)
		print_obj_key(e);
	if (e->o.jetpack == 1)
		print_jetpack(e);
}
