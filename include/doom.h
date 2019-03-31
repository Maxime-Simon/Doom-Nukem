/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:55 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/27 18:37:30 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H
# define TS 100
# include "color.h"
# include "math.h"
# include "keyboard.h"
# include "../Libft/libft.h"
# include "../Headers/SDL.h"

typedef struct		s_objects{
	int				cible;
	SDL_Surface		*cib_tex;
	char			*cib_str;
	int				flashlight;
	SDL_Surface		*fl_tex;
	char			*fl_str;
	int				map;
	SDL_Surface		*map_tex;
	char			*map_str;
	int				key;
	SDL_Surface		*key_tex;
	char			*key_str;
	int				tp;
}					t_objects;

typedef struct		s_tex{
	SDL_Surface		*text0;
	char			*tstr0;
	SDL_Surface		*text1;
	char			*tstr1;
	SDL_Surface		*text2;
	char			*tstr2;
	SDL_Surface		*text3;
	char			*tstr3;
	int				lighton;
}					t_tex;

typedef	struct		s_map{
	char			**grid;
	Uint32			*data_map;
	SDL_Surface		*surf_map;
	int				t_x;
	int				t_y;
	int				img_x;
	int				img_y;
	char			cur_bl;
}					t_map;

typedef struct		s_column{
	float			d_mur;
	int				num;
	int				face;
	float			xi;
	float			yi;
}					t_column;

typedef	struct		s_perso{
	int				x_map;
	int				y_map;
	float			pos_x;
	float			pos_y;
	int				mv_x;
	int				mv_y;
	float			mv_z;
	float			mv_r;
	int				h;
	int				angle;
	int				pos_z;
	int				vd;
}					t_perso;

typedef struct		s_env{
	int				f;
	t_perso			*pe;
	t_map			*map;
	t_column		*c;
	t_tex			t;
	t_objects		o;
	SDL_Window		*win;
	SDL_Surface		*surf;
	SDL_Surface		*init;
	SDL_Event		event;
	Uint32			*data;
	int				run;
	int				win_x;
	int				win_y;
	void			*img;
	int				psi;
	int				p;
	int				pm;
}					t_env;

typedef	struct		s_ray{
	float			coef;
	float			a;
	float			dd;
	float			dx;
	float			dy;
	int				cfxa;
	int				cfxb;
	int				cfxc;
	int				cfxd;
	int				cfya;
	int				cfyb;
	int				cfyc;
	int				cfyd;
}					t_ray;

typedef	struct		s_dist{
	float			xm;
	float			ym;
	float			ya;
	int				tx;
	float			am;
	float			bm;
	float			xa;
	int				ty;
}					t_dist;

typedef struct		s_render{
	int				nx;
	int				nz;
	int				ny;
	int				z;
}					t_render;

/*
**	expose_hook.c
*/
int					expose_hook(t_env *e);

/*
**	get_grid.c
*/
void				get_grid(t_env *e);

/*
**	get_map.c
*/
int					get_map(t_map *map, int fd);

/*
**	get_objects.c
*/
void				get_obj(t_env *e);

/*
**	get_perso.c
*/
void				get_perso(t_env *e, t_perso *p);
void				erase_player(t_env *e, int y_map, int x_map);

/*
**	get_textures.c
*/
void				init_textures(t_env *e);
void				init_objects(t_env *e);

/*
**	get_view.c
*/
void				get_view(t_env *e);

/*
**	init_sdl.c
*/
int					init_sdl(t_env *e);

/*
**	key_hook.c
*/
int					key_press(int k, t_env *e);
int					key_release(int k, t_env *e);

/*
**	mouse_hook.c
*/
int					mouse_move_hook(SDL_Event event, t_env *e);

/*
**	print_hud.c
*/
void				print_hud(t_env *e);

/*
**	raycast.c
*/
void				raycast(float d, t_perso *p, t_map *m, t_column *c);

/*
**	render.c
*/
uint32_t			render(t_render r, int h, t_column c, t_env *e);

/*
**	utils.c
*/
void				check_close_bl(t_env *e,t_perso *p);
void				ft_is_perso(char **grid);
int					ft_exit(int i);
int					set_color(int r, int g, int b);
void				find_block(t_env *e, t_perso *p);

#endif
