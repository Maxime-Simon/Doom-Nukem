/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:02:11 by madecreu          #+#    #+#             */
/*   Updated: 2019/05/03 15:23:39 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_H
# define EDIT_H

# include "../libft/libft.h"
# include "../headers/SDL.h"

# define WE 1920
# define HE 1216
# define DEF_W 15
# define DEF_H 15
# define FPS 60

typedef struct		s_text
{
	SDL_Surface		*text0;
	SDL_Surface		*text1;
	SDL_Surface		*text2;
	SDL_Surface		*text3;
	SDL_Surface		*text4;
	SDL_Surface		*text5;
	SDL_Surface		*text6;
	SDL_Surface		*text7;
	SDL_Surface		*text8;
	SDL_Surface		*text9;
	SDL_Surface		*item0;
	SDL_Surface		*item1;
	SDL_Surface		*item2;
	SDL_Surface		*item3;
	SDL_Surface		*item4;
}					t_text;

typedef struct		s_debug
{
	int				i;
}					t_debug;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_edit
{
	int				brush;
	int				edit;
}					t_edit;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*to_window;
	SDL_Surface		*modifier;
	char			*pixels;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_map
{
	int				max_x;
	int				max_y;
	int				**map;
	char			*name;
}					t_map;

typedef struct		s_env
{
	t_sdl			sdl;
	t_map			map;
	t_edit			edit;
	t_debug			debug;
	t_text			text;
}					t_env;

/*
**	draw1.c
*/
void				draw_map(t_env *env);

/*
**	draw2.c
*/
void				draw_text(t_env *env, int w_tile, int h_tile, t_point pos);
void				draw_rect(t_env *env, t_point s1, t_point s2, int color);

/*
**	draw3.c
*/
void				draw_text4(t_env *env, int w_tile, int h_tile, t_point pos);
void				draw_option5(t_env *env);

/*
**	exit.c
*/
void				save_and_exit(t_env	*env);
void				exit_doom(t_env *env, int value, const char *error);

/*
**	main.c
*/
void				event(t_env *env);
void				replace_item(t_env *env, int x, int y);

/*
**	map.c
*/
void				select_and_print(int value, int fd);
t_map				create_map(t_env *env, int w, int h);
void				pixel_put(char *pixels, int x, int y, int color);
t_map				fill_map(t_map map);

/*
**	mouse_event.c
*/
void				mouse_motion(t_env *env);
void				mouse_release(t_env *env);
void				mouse_press(t_env *env);
void				mouse_press2(t_env *env, int x, int y);
void				mouse_press3(t_env *env, int x, int y);

#endif
