/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:25:09 by vapiatko          #+#    #+#             */
/*   Updated: 2019/05/02 20:06:13 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static void		init(t_env *e)
{
	e->win_x = 900;
	e->win_y = 700;
	e->map->img_x = 250;
	e->map->img_y = 250;
	e->pe->pos_x = -1;
	e->pe->pos_z = 0;
	e->pe->vd = TS / 10;
	e->pe->angle = 0;
	e->pe->mv_z = 0;
	e->pe->mv_y = 0;
	e->pe->mv_x = 0;
	e->pe->mv_r = 0;
	e->pe->mv_h = 0;
	e->pe->fh = -TS;
	e->pe->hh = TS;
	e->pe->pos_z = 0;
	e->pm = 0;
	e->run = 1;
	e->o.offtorch = 0;
	e->o.ontorch = 0;
	e->o.lightbar = 0;
	e->o.flint = 0;
	e->o.key = 0;
	e->o.jetpack = 0;
}

static void		init_audio(void)
{
	SDL_AudioSpec		audioout;
	SDL_AudioDeviceID	deviceid;
	Uint8				*audiobuf;
	Uint32				audiobuflen;

	SDL_LoadWAV("/audio/music.wav", &audioout, &audiobuf, &audiobuflen);
	deviceid = SDL_OpenAudioDevice(NULL, 0, &audioout, NULL, 0);
	SDL_QueueAudio(deviceid, audiobuf, audiobuflen);
	SDL_PauseAudioDevice(deviceid, 0);
	if (SDL_GetQueuedAudioSize(deviceid) == 0)
	{
		SDL_ClearQueuedAudio(deviceid);
		SDL_CloseAudioDevice(deviceid);
	}
	SDL_FreeWAV(audiobuf);
}

static void		event_sdl(t_env *e)
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
			if (e->event.type == SDL_MOUSEMOTION)
				mouse_move_hook(e->event, e);
		}
		SDL_WarpMouseInWindow(e->win, e->win_x / 2, e->win_y / 2);
		expose_hook(e);
	}
}

int				init_sdl(t_env *e)
{
	init(e);
	build_text(e);
	init_textures(e);
	init_objects(e);
	SDL_Init(0);
	SDL_InitSubSystem(SDL_INIT_TIMER);
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	SDL_InitSubSystem(SDL_INIT_VIDEO);
	init_audio();
	SDL_ShowCursor(SDL_DISABLE);
	e->win = SDL_CreateWindow("Doom", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, e->win_x, e->win_y, 0);
	e->init = SDL_GetWindowSurface(e->win);
	SDL_ShowSimpleMessageBox(e->tx.sdl_flag, "Hello", e->tx.start, NULL);
	SDL_ShowSimpleMessageBox(e->tx.sdl_flag, "World!", e->tx.start2, NULL);
	event_sdl(e);
	return (0);
}
