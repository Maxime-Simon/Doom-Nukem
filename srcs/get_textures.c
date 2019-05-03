/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:33:26 by vapiatko          #+#    #+#             */
/*   Updated: 2019/04/30 16:41:20 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	free_text_and_obj(t_env *e)
{
	SDL_FreeSurface(e->t.text0);
	SDL_FreeSurface(e->t.text1);
	SDL_FreeSurface(e->t.text2);
	SDL_FreeSurface(e->t.text3);
	SDL_FreeSurface(e->t.text4);
	SDL_FreeSurface(e->t.text5);
	SDL_FreeSurface(e->t.text6);
	SDL_FreeSurface(e->t.text7);
	SDL_FreeSurface(e->o.ontrc_tex);
	SDL_FreeSurface(e->o.offtrc_tex);
	SDL_FreeSurface(e->o.lightbar_tex);
	SDL_FreeSurface(e->o.flint_tex);
	SDL_FreeSurface(e->o.map_tex);
	SDL_FreeSurface(e->o.key_tex);
	SDL_FreeSurface(e->o.jpk_tex);
	SDL_FreeSurface(e->o.end_tex);
}

void	init_textures(t_env *e)
{
	if ((e->t.text0 = SDL_LoadBMP("./textures/brick1.bmp")) == NULL
		|| (e->t.text1 = SDL_LoadBMP("./textures/brick2.bmp")) == NULL
		|| (e->t.text2 = SDL_LoadBMP("./textures/brick3.bmp")) == NULL
		|| (e->t.text3 = SDL_LoadBMP("./textures/concrete.bmp")) == NULL
		|| (e->t.text4 = SDL_LoadBMP("./textures/stones.bmp")) == NULL
		|| (e->t.text5 = SDL_LoadBMP("./textures/wood.bmp")) == NULL
		|| (e->t.text6 = SDL_LoadBMP("./textures/moon.bmp")) == NULL
		|| (e->t.text7 = SDL_LoadBMP("./textures/door.bmp")) == NULL)
		ft_exit(8);
	e->t.tstr0 = (char *)e->t.text0->pixels;
	e->t.tstr1 = (char *)e->t.text1->pixels;
	e->t.tstr2 = (char *)e->t.text2->pixels;
	e->t.tstr3 = (char *)e->t.text3->pixels;
	e->t.tstr4 = (char *)e->t.text4->pixels;
	e->t.tstr5 = (char *)e->t.text5->pixels;
	e->t.tstr6 = (char *)e->t.text6->pixels;
	e->t.tstr7 = (char *)e->t.text7->pixels;
}

void	init_objects(t_env *e)
{
	if ((e->o.ontrc_tex = SDL_LoadBMP("./objects/on_torch.bmp")) == NULL
		|| (e->o.offtrc_tex = SDL_LoadBMP("./objects/off_torch.bmp")) == NULL
		|| (e->o.lightbar_tex = SDL_LoadBMP("./objects/timelamp.bmp")) == NULL
		|| (e->o.flint_tex = SDL_LoadBMP("./objects/flint.bmp")) == NULL
		|| (e->o.map_tex = SDL_LoadBMP("./objects/rose.bmp")) == NULL
		|| (e->o.key_tex = SDL_LoadBMP("./objects/key.bmp")) == NULL
		|| (e->o.jpk_tex = SDL_LoadBMP("./objects/jetpack.bmp")) == NULL
		|| (e->o.end_tex = SDL_LoadBMP("./objects/flag.bmp")) == NULL)
		ft_exit(8);
	e->o.ontrc_str = e->o.ontrc_tex->pixels;
	e->o.offtrc_str = e->o.offtrc_tex->pixels;
	e->o.lightbar_str = e->o.lightbar_tex->pixels;
	e->o.flint_str = e->o.flint_tex->pixels;
	e->o.map_str = e->o.map_tex->pixels;
	e->o.key_str = e->o.key_tex->pixels;
	e->o.jpk_str = e->o.jpk_tex->pixels;
	e->o.end_str = e->o.end_tex->pixels;
}
