/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:45:44 by madecreu          #+#    #+#             */
/*   Updated: 2019/04/26 16:59:12 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/edit.h"

void	draw_rect(t_env *env, t_point s1, t_point s2, int color)
{
	int temp;

	temp = s1.x;
	while (s1.y <= s2.y)
	{
		while (s1.x <= s2.x)
		{
			pixel_put(env->sdl.pixels, s1.x, s1.y, color);
			s1.x++;
		}
		s1.x = temp;
		s1.y++;
	}
}

void	draw_anormal_wall(t_env *env, int w_tile, int h_tile, t_point pos)
{
	if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 10)
		draw_rect(env, (t_point){pos.x, pos.y + (h_tile - 3) / 7 * 6},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0x00ffff);
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 11)
		draw_rect(env, (t_point){pos.x, pos.y + ((h_tile - 3) / 7) * 5},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0x00ffff);
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 12)
		draw_rect(env, (t_point){pos.x, pos.y + ((h_tile - 3) / 7) * 4},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0x00ffff);
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 13)
		draw_rect(env, (t_point){pos.x, pos.y + ((h_tile - 3) / 7) * 3},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0x00ffff);
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 14)
		draw_rect(env, (t_point){pos.x, pos.y + ((h_tile - 3) / 7) * 2},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0x00ffff);
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 15)
		draw_rect(env, (t_point){pos.x, pos.y + (h_tile - 3) / 7},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0x00ffff);
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 16)
		draw_rect(env, (t_point){pos.x, pos.y},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0x00ffff);
}

void	draw_text3(t_env *env, int w_tile, int h_tile, t_point pos)
{
	if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 8)
	{
		draw_rect(env, (t_point){pos.x, pos.y},
			(t_point){pos.x + w_tile - 3, pos.y + h_tile - 3}, 0xffffff);
		draw_rect(env, (t_point){pos.x + 1, pos.y + 1},
			(t_point){pos.x + w_tile - 4, pos.y + h_tile - 4}, 0x000000);
	}
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -2)
		SDL_BlitScaled(env->text.item1, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -3)
		SDL_BlitScaled(env->text.item2, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	draw_text4(env, w_tile, h_tile, pos);
}

void	draw_text2(t_env *env, int w_tile, int h_tile, t_point pos)
{
	if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -4)
		SDL_BlitScaled(env->text.item3, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -5)
		SDL_BlitScaled(env->text.item4, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -6)
		SDL_BlitScaled(env->text.text6, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -7)
		SDL_BlitScaled(env->text.text7, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -8)
		SDL_BlitScaled(env->text.text8, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x - 1, pos.y - 1, w_tile - 1, h_tile - 1});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 9)
		SDL_BlitScaled(env->text.text9, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	draw_text3(env, w_tile, h_tile, pos);
}

void	draw_text(t_env *env, int w_tile, int h_tile, t_point pos)
{
	if (env->map.map[pos.y / h_tile][pos.x / w_tile] >= 10)
		draw_anormal_wall(env, w_tile, h_tile, pos);
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 1)
		SDL_BlitScaled(env->text.text0, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 2)
		SDL_BlitScaled(env->text.text1, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 3)
		SDL_BlitScaled(env->text.text2, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 4)
		SDL_BlitScaled(env->text.text3, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 5)
		SDL_BlitScaled(env->text.text4, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 6)
		SDL_BlitScaled(env->text.text5, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	else if (env->map.map[pos.y / h_tile][pos.x / w_tile] == -1)
		SDL_BlitScaled(env->text.item0, NULL, env->sdl.modifier,
			&(SDL_Rect){pos.x, pos.y, w_tile - 2, h_tile - 2});
	draw_text2(env, w_tile, h_tile, pos);
}
