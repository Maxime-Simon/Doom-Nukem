/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:33:26 by vapiatko          #+#    #+#             */
/*   Updated: 2019/03/28 18:05:20 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	init_textures(t_env *e)
{
	e->t.text0 = SDL_LoadBMP("/textures/test.bmp");
	if (e->t.text0)
		e->t.tstr0 = (char *)e->t.text0->pixels;
	else
		printf("SDL_Init failed: %s\n", SDL_GetError());
	e->t.text1 = SDL_LoadBMP("/textures/test1.bmp");
	e->t.tstr1 = (char *)e->t.text1->pixels;
	e->t.text2 = SDL_LoadBMP("/textures/test2.bmp");
	e->t.tstr2 = (char *)e->t.text2->pixels;
	e->t.text3 = SDL_LoadBMP("/textures/test3.bmp");
	e->t.tstr3 = (char *)e->t.text3->pixels;
}

void	init_objects(t_env *e)
{
	e->o.fl_tex = SDL_LoadBMP("/objects/torch.bmp");
	e->o.fl_str = e->o.fl_tex->pixels;
	e->o.map_tex = SDL_LoadBMP("/objects/rose.bmp");
	e->o.map_str = e->o.map_tex->pixels;
	e->o.key_tex = SDL_LoadBMP("/objects/key-1.bmp");
	e->o.key_str = e->o.key_tex->pixels;
	e->o.cib_tex = SDL_LoadBMP("/objects/target.bmp");
	e->o.cib_str = e->o.cib_tex->pixels;
}
