/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:26:16 by madecreu          #+#    #+#             */
/*   Updated: 2019/05/03 15:22:47 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/edit.h"

int		check_arg(int w, int h)
{
	int i;

	if (w > 64 || h > 64 || w < 2 || h < 2)
	{
		ft_putstr("La taille x et/ou y de votre map ne doit");
		ft_putendl(" pas être superieur a 64 ni inferieur a 2");
		return (0);
	}
	i = 2;
	while (i <= w && i <= 64)
	{
		if (w == i)
		{
			i = 2;
			while (i <= h && i <= 64)
			{
				if (h == i)
					return (1);
				i *= 2;
			}
		}
		i *= 2;
	}
	ft_putendl("La taille x ou y de votre map n'est pas une puissance de 2");
	return (0);
}

void	replace_item(t_env *env, int x, int y)
{
	int		i;
	int		c;

	i = 0;
	while (i < env->map.max_y)
	{
		c = 0;
		while (c < env->map.max_x)
		{
			if (env->map.map[i][c] == env->edit.brush)
				env->map.map[i][c] = 0;
			c++;
		}
		i++;
	}
	env->map.map[y / (HE / env->map.max_y)][x / (HE / env->map.max_x)] =
	env->edit.brush;
}

void	event(t_env *env)
{
	int run;

	run = 1;
	while (run)
	{
		while (SDL_PollEvent(&env->sdl.event))
		{
			if (env->sdl.event.type == SDL_QUIT
				|| (env->sdl.event.type == SDL_KEYDOWN
				&& env->sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				run = 0;
			else if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN)
				mouse_press(env);
			else if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
				mouse_release(env);
			else if (env->sdl.event.type == SDL_MOUSEMOTION)
				mouse_motion(env);
		}
		draw_map(env);
		SDL_BlitSurface(env->sdl.modifier, NULL, env->sdl.to_window, NULL);
		SDL_UpdateWindowSurface(env->sdl.win);
	}
}

void	init_bmp(t_env *env)
{
	if ((env->text.text0 = SDL_LoadBMP("textures/brick1.bmp")) == NULL
		|| (env->text.text1 = SDL_LoadBMP("textures/brick2.bmp")) == NULL
		|| (env->text.text2 = SDL_LoadBMP("textures/brick3.bmp")) == NULL
		|| (env->text.text3 = SDL_LoadBMP("textures/concrete.bmp")) == NULL
		|| (env->text.text4 = SDL_LoadBMP("textures/stones.bmp")) == NULL
		|| (env->text.text5 = SDL_LoadBMP("textures/wood.bmp")) == NULL
		|| (env->text.text6 = SDL_LoadBMP("textures/spawn.bmp")) == NULL
		|| (env->text.text7 = SDL_LoadBMP("textures/door.bmp")) == NULL
		|| (env->text.text8 = SDL_LoadBMP("textures/end.bmp")) == NULL
		|| (env->text.text9 = SDL_LoadBMP("textures/glass.bmp")) == NULL
		|| (env->text.item0 = SDL_LoadBMP("objects/flint.bmp")) == NULL
		|| (env->text.item1 = SDL_LoadBMP("objects/jetpack.bmp")) == NULL
		|| (env->text.item2 = SDL_LoadBMP("objects/key.bmp")) == NULL
		|| (env->text.item3 = SDL_LoadBMP("objects/off_torch.bmp")) == NULL
		|| (env->text.item4 = SDL_LoadBMP("objects/rose.bmp")) == NULL)
		exit_doom(env, 4, SDL_GetError());
}

void	start_edit(int w, int h, char *filename)
{
	t_sdl	sdl;
	t_env	env;

	if (check_arg(w, h))
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
			exit_doom(&env, 4, SDL_GetError());
		if ((sdl.win = SDL_CreateWindow("Editeur", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WE, HE, SDL_WINDOW_SHOWN)) == NULL)
			exit_doom(&env, 4, SDL_GetError());
		if ((sdl.modifier = SDL_CreateRGBSurface(0, WE, HE, 32,
			0, 0, 0, 0)) == NULL)
			exit_doom(&env, 4, SDL_GetError());
		if ((sdl.to_window = SDL_GetWindowSurface(sdl.win)) == NULL)
			exit_doom(&env, 4, SDL_GetError());
		sdl.pixels = (char*)(sdl.modifier->pixels);
		env.sdl = sdl;
		create_map(&env, w, h);
		env.map.name = ft_strjoin("maps/", filename);
		env.edit.brush = 0;
		env.edit.edit = 0;
		init_bmp(&env);
		event(&env);
		exit_doom(&env, 1, "");
	}
}
