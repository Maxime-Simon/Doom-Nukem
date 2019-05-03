/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:55 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/03 18:57:44 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H
# define TS 1000
# define TIME_L 32000
# define GRAVITY 4
# define CT 0.0174533
# define NB_THREAD 5
# include "color.h"
# include "math.h"
# include "keyboard.h"
# include "../libft/libft.h"
# include "../headers/SDL.h"

typedef struct		s_text
{
	int				sdl_flag;
	char			*start;
	char			*start2;
	char			*end;
}					t_text;

typedef struct		s_objects
{
	int				spr_posx;
	int				spr_posy;
	char			wich_spr;
	int				jetpack;
	SDL_Surface		*jpk_tex;
	char			*jpk_str;
	int				ontorch;
	SDL_Surface		*ontrc_tex;
	char			*ontrc_str;
	int				lightbar;
	SDL_Surface		*lightbar_tex;
	char			*lightbar_str;
	int				offtorch;
	SDL_Surface		*offtrc_tex;
	char			*offtrc_str;
	int				flint;
	SDL_Surface		*flint_tex;
	char			*flint_str;
	int				map;
	SDL_Surface		*map_tex;
	char			*map_str;
	int				key;
	SDL_Surface		*key_tex;
	char			*key_str;
	Uint32			trc_end;
	int				lighton;
	SDL_Surface		*end_tex;
	char			*end_str;
	int				spr_ct_flint;
	int				spr_ct_map;
	int				spr_ct_torch;
	int				spr_ct_jetpack;
	int				spr_ct_end;
	int				spr_ct_key;
}					t_objects;

typedef struct		s_tex
{
	SDL_Surface		*text0;
	char			*tstr0;
	SDL_Surface		*text1;
	char			*tstr1;
	SDL_Surface		*text2;
	char			*tstr2;
	SDL_Surface		*text3;
	char			*tstr3;
	SDL_Surface		*text4;
	char			*tstr4;
	SDL_Surface		*text5;
	char			*tstr5;
	SDL_Surface		*text6;
	char			*tstr6;
	SDL_Surface		*text7;
	char			*tstr7;
}					t_tex;

typedef	struct		s_map
{
	char			**grid;
	Uint32			*data_map;
	SDL_Surface		*surf_map;
	int				t_x;
	int				t_y;
	int				img_x;
	int				img_y;
	char			cur_bl;
}					t_map;

typedef struct		s_column
{
	float			d_mur;
	int				num;
	int				last_num;
	int				face;
	float			h;
	float			xi;
	float			yi;
	int				nb_wall;
	int				this_height;
	int				last_height;
}					t_column;

typedef	struct		s_perso
{
	int				x_map;
	int				y_map;
	float			pos_x;
	float			pos_y;
	int				pos_z;
	int				mv_x;
	int				mv_y;
	float			mv_z;
	float			mv_r;
	float			mv_h;
	float			h;
	float			fh;
	float			hh;
	int				angle;
	int				on_floor;
	float			vd;
}					t_perso;

typedef struct		s_env
{
	t_perso			*pe;
	t_map			*map;
	t_column		*c;
	t_text			tx;
	t_tex			t;
	t_objects		o;
	SDL_Window		*win;
	SDL_Surface		*surf;
	SDL_Surface		*init;
	SDL_mutex		*mutex;
	SDL_Event		event;
	Uint32			*data;
	int				run;
	int				win_x;
	int				win_y;
	int				pm;
	int				deb;
}					t_env;

typedef	struct		s_ray
{
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

/*
**	build_text.c
*/
void				build_text(t_env *e);

/*
**	expose_hook.c
*/
int					expose_hook(t_env *e);

/*
**	find_height.c
*/
int					find_height(char c);

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
int					get_obj(t_env *e);

/*
**	get_perso.c
*/
void				get_perso(t_env *e, t_perso *p);
void				erase_player(t_env *e, int y_map, int x_map);
void				make_player(t_env *e);

/*
**	get_textures.c
*/
void				init_textures(t_env *e);
void				init_objects(t_env *e);

/*
**	get_view.c
*/
int					get_view(void *e);

/*
**	init_raycast.c
*/
t_ray				init_raycast(float d, t_env *e, t_column *c);

/*
**	init_sdl.c
*/
int					init_sdl(t_env *e);

/*
**	is_wall.c
*/
int					is_visible_wall(char c);
int					is_touchable_wall(char c);
int					is_end_wall(char c);

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
**	print_sprite.c
*/
void				print_sprites(t_env *e);

/*
**	print_torch.c
*/
void				print_torch(t_env *e);

/*
**	raycast.c
*/
void				raycast(t_ray r, t_perso *p, t_map *m, t_column *c);

/*
**	utils.c
*/
void				ft_is_perso(char **grid);
int					ft_exit(int i);
void				find_block(t_env *e, t_perso *p);
void				check_close_bl(t_env *e, t_perso *p);
void				ft_is_end(char **grid);

/*
**	editeur
*/
void				start_edit(int w, int h, char *filename);

void				make_co(int i, t_env *e, t_column c);
int					multi_thread(t_env *e);

#endif
