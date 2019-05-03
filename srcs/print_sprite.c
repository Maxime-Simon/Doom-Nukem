/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:20:26 by vapiatko          #+#    #+#             */
/*   Updated: 2019/05/03 16:27:21 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static void		print_spr(t_env *e, SDL_Surface *sprite)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	src.h = 64;
	src.w = 64;
	dst.x = e->o.spr_posx;
	dst.y = (-e->pe->pos_z + e->win_y / 2) - (e->pe->fh + TS) / 256;
	dst.w = e->o.spr_posy;
	dst.h = dst.w;
	SDL_BlitScaled(sprite, &src, e->init, &dst);
}

void			print_sprites(t_env *e)
{
	if (e->o.spr_posx >= 0)
	{
		if (e->o.wich_spr == 'F' && e->o.spr_ct_flint == 0)
			print_spr(e, e->o.flint_tex);
		else if (e->o.wich_spr == 'T' && e->o.spr_ct_torch == 0)
			print_spr(e, e->o.offtrc_tex);
		else if (e->o.wich_spr == 'M' && e->o.spr_ct_map == 0)
			print_spr(e, e->o.map_tex);
		else if (e->o.wich_spr == 'K' && e->o.spr_ct_key == 0)
			print_spr(e, e->o.key_tex);
		else if (e->o.wich_spr == 'J' && e->o.spr_ct_jetpack == 0)
			print_spr(e, e->o.jpk_tex);
		else if (e->o.wich_spr == 'Z' && e->o.spr_ct_end == 0)
			print_spr(e, e->o.end_tex);
	}
	SDL_UnlockMutex(e->mutex);
}
