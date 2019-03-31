/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:09 by vapiatko          #+#    #+#             */
/*   Updated: 2019/03/28 17:26:01 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	init(t_env *e)
{
	e->win_x = 900;
	e->win_y = 700;
	e->map->img_x = 250;
	e->map->img_y = 250;
	e->pe->pos_x = -1;
	e->pe->pos_z = 0;
	e->pe->vd = 3;
	e->pe->angle = 0;
	e->pe->mv_z = 0;
	e->pe->mv_y = 0;
	e->pe->mv_x = 0;
	e->pe->mv_r = 0;
	e->pe->h = 32;
	e->pe->pos_z = 0;
	e->psi = 0;
	e->p = 0;
	e->pm = 0;
	e->run = 1;
	e->f = 0;
	e->o.cible = 0;
	e->o.flashlight = 0;
	e->o.key = 0;
	e->o.tp = 0;
}

void	init_audio()
{
	SDL_AudioSpec audioout;
	SDL_AudioDeviceID deviceid;
	Uint8 *audiobuf;
	Uint32 audiobuflen;

	SDL_LoadWAV("/audio/music.wav", &audioout, &audiobuf, &audiobuflen);
	deviceid = SDL_OpenAudioDevice(NULL, 0, &audioout, NULL, 0);
	SDL_QueueAudio(deviceid, audiobuf, audiobuflen);
	SDL_PauseAudioDevice(deviceid, 0);
	if (SDL_GetQueuedAudioSize(deviceid) == 0)
	{
		SDL_CloseAudioDevice(deviceid);
		SDL_FreeWAV(audiobuf);
	}
}

void	event_sdl(t_env *e)
{
	while (e->run)
	{
		while (SDL_PollEvent(&e->event))
		{
			if (e->event.type == SDL_QUIT)
				e->run = 0;
			if (e->event.type == SDL_KEYDOWN)
				key_press(e->event.key.keysym.scancode, e);
			if (e->event.type == SDL_KEYUP)
				key_release(e->event.key.keysym.scancode, e);
		}
		if (e->event.type == SDL_MOUSEMOTION)
			mouse_move_hook(e->event, e);
		SDL_WarpMouseInWindow(e->win, e->win_x / 2, e->win_y / 2);
		expose_hook(e);
	}
}

int		init_sdl(t_env *e)
{
	init(e);
	init_textures(e);
	init_objects(e);
	SDL_Init(SDL_INIT_EVERYTHING);
	// init_audio();
	SDL_ShowCursor(SDL_DISABLE);
	e->win = SDL_CreateWindow("doom-nukem", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, e->win_x, e->win_y, 0);
	e->init = SDL_GetWindowSurface(e->win);
	event_sdl(e);
	exit(1);
	return (0);
}
