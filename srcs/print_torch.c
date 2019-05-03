/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_torch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:22:29 by vapiatko          #+#    #+#             */
/*   Updated: 2019/04/21 15:58:31 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static void		print_obj_offtorch(t_env *e)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 64;
	srcrect.h = 64;
	dstrect.x = e->win_x - 84;
	dstrect.y = 20;
	dstrect.w = 64;
	dstrect.h = 64;
	SDL_BlitSurface(e->o.offtrc_tex, &srcrect, e->init, &dstrect);
}

static void		print_obj_ontorch(t_env *e)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 64;
	srcrect.h = 64;
	dstrect.x = e->win_x - 84;
	dstrect.y = 20;
	dstrect.w = 64;
	dstrect.h = 64;
	SDL_BlitSurface(e->o.ontrc_tex, &srcrect, e->init, &dstrect);
}

static void		print_lightbar(t_env *e)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = (2 * (e->o.trc_end - SDL_GetTicks()) / 1000 % 64);
	srcrect.h = 3;
	dstrect.x = e->win_x - 84;
	dstrect.y = 85;
	dstrect.w = (2 * (e->o.trc_end - SDL_GetTicks()) / 1000 % 64);
	dstrect.h = 3;
	SDL_BlitSurface(e->o.lightbar_tex, &srcrect, e->init, &dstrect);
}

static void		print_flint(t_env *e)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	srcrect.x = 0;
	srcrect.y = 0;
	srcrect.w = 64;
	srcrect.h = 64;
	dstrect.x = e->win_x - 84;
	dstrect.y = 104;
	dstrect.w = 64;
	dstrect.h = 64;
	SDL_BlitSurface(e->o.flint_tex, &srcrect, e->init, &dstrect);
}

void			print_torch(t_env *e)
{
	if (e->o.lighton == 1)
		print_obj_ontorch(e);
	if (e->o.lightbar == 1 && e->o.lighton == 1)
		print_lightbar(e);
	if (e->o.offtorch == 1 && e->o.lighton == 0)
		print_obj_offtorch(e);
	if (e->o.flint == 1)
		print_flint(e);
}
