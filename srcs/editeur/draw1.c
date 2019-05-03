/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:45:38 by madecreu          #+#    #+#             */
/*   Updated: 2019/04/26 16:59:10 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/edit.h"

void	draw_option4(t_env *env)
{
	SDL_BlitScaled(env->text.item3, NULL,
		env->sdl.modifier, &(SDL_Rect){1675, 300, 50, 50});
	SDL_BlitScaled(env->text.item4, NULL,
		env->sdl.modifier, &(SDL_Rect){1800, 300, 50, 50});
	SDL_BlitScaled(env->text.text6, NULL,
		env->sdl.modifier, &(SDL_Rect){1300, 500, 50, 50});
	SDL_BlitScaled(env->text.text9, NULL,
		env->sdl.modifier, &(SDL_Rect){1400, 500, 50, 50});
	SDL_BlitScaled(env->text.text7, NULL,
		env->sdl.modifier, &(SDL_Rect){1500, 500, 50, 50});
	draw_rect(env, (t_point){1600, 500}, (t_point){1650, 550}, 0xffffff);
	draw_rect(env, (t_point){1601, 501}, (t_point){1649, 549}, 0x000000);
	draw_rect(env, (t_point){1700, 500}, (t_point){1750, 505}, 0xffaa00);
	draw_rect(env, (t_point){1700, 510}, (t_point){1750, 515}, 0xffbb00);
	draw_rect(env, (t_point){1700, 520}, (t_point){1750, 525}, 0xffcc00);
	draw_rect(env, (t_point){1700, 530}, (t_point){1750, 535}, 0xffdd00);
	draw_rect(env, (t_point){1700, 540}, (t_point){1750, 545}, 0xffee00);
	SDL_BlitScaled(env->text.text8, NULL,
		env->sdl.modifier, &(SDL_Rect){1800, 500, 50, 50});
	draw_rect(env, (t_point){1250, 743}, (t_point){1300, 750}, 0x00ffff);
	draw_rect(env, (t_point){1350, 736}, (t_point){1400, 750}, 0x00ffff);
	draw_rect(env, (t_point){1450, 729}, (t_point){1500, 750}, 0x00ffff);
	draw_rect(env, (t_point){1550, 722}, (t_point){1600, 750}, 0x00ffff);
	draw_rect(env, (t_point){1650, 715}, (t_point){1700, 750}, 0x00ffff);
	draw_option5(env);
}

void	draw_option3(t_env *env)
{
	if (env->edit.brush == 15)
		draw_rect(env, (t_point){1740, 690}, (t_point){1810, 760}, 0x00ff00);
	else if (env->edit.brush == 16)
		draw_rect(env, (t_point){1840, 690}, (t_point){1910, 760}, 0x00ff00);
	draw_rect(env, (t_point){1250, 100}, (t_point){1300, 150}, 0xffffff);
	SDL_BlitScaled(env->text.text0, NULL,
		env->sdl.modifier, &(SDL_Rect){1350, 100, 50, 50});
	SDL_BlitScaled(env->text.text1, NULL,
		env->sdl.modifier, &(SDL_Rect){1450, 100, 50, 50});
	SDL_BlitScaled(env->text.text2, NULL,
		env->sdl.modifier, &(SDL_Rect){1550, 100, 50, 50});
	SDL_BlitScaled(env->text.text3, NULL,
		env->sdl.modifier, &(SDL_Rect){1650, 100, 50, 50});
	SDL_BlitScaled(env->text.text4, NULL,
		env->sdl.modifier, &(SDL_Rect){1750, 100, 50, 50});
	SDL_BlitScaled(env->text.text5, NULL,
		env->sdl.modifier, &(SDL_Rect){1850, 100, 50, 50});
	SDL_BlitScaled(env->text.item0, NULL,
		env->sdl.modifier, &(SDL_Rect){1300, 300, 50, 50});
	SDL_BlitScaled(env->text.item1, NULL,
		env->sdl.modifier, &(SDL_Rect){1425, 300, 50, 50});
	SDL_BlitScaled(env->text.item2, NULL,
		env->sdl.modifier, &(SDL_Rect){1550, 300, 50, 50});
	draw_option4(env);
}

void	draw_option2(t_env *env)
{
	if (env->edit.brush == -5)
		draw_rect(env, (t_point){1790, 290}, (t_point){1860, 360}, 0x00ff00);
	else if (env->edit.brush == -6)
		draw_rect(env, (t_point){1290, 490}, (t_point){1360, 560}, 0x00ff00);
	else if (env->edit.brush == 9)
		draw_rect(env, (t_point){1390, 490}, (t_point){1460, 560}, 0x00ff00);
	else if (env->edit.brush == -7)
		draw_rect(env, (t_point){1490, 490}, (t_point){1560, 560}, 0x00ff00);
	else if (env->edit.brush == 8)
		draw_rect(env, (t_point){1590, 490}, (t_point){1660, 560}, 0x00ff00);
	else if (env->edit.brush == 7)
		draw_rect(env, (t_point){1690, 490}, (t_point){1760, 560}, 0x00ff00);
	else if (env->edit.brush == -8)
		draw_rect(env, (t_point){1790, 490}, (t_point){1860, 560}, 0x00ff00);
	else if (env->edit.brush == 10)
		draw_rect(env, (t_point){1240, 690}, (t_point){1310, 760}, 0x00ff00);
	else if (env->edit.brush == 11)
		draw_rect(env, (t_point){1340, 690}, (t_point){1410, 760}, 0x00ff00);
	else if (env->edit.brush == 12)
		draw_rect(env, (t_point){1440, 690}, (t_point){1510, 760}, 0x00ff00);
	else if (env->edit.brush == 13)
		draw_rect(env, (t_point){1540, 690}, (t_point){1610, 760}, 0x00ff00);
	else if (env->edit.brush == 14)
		draw_rect(env, (t_point){1640, 690}, (t_point){1710, 760}, 0x00ff00);
	draw_option3(env);
}

void	draw_option(t_env *env)
{
	draw_rect(env, (t_point){1217, 0}, (t_point){1919, 999}, 0x000000);
	if (env->edit.brush == 0)
		draw_rect(env, (t_point){1240, 90}, (t_point){1310, 160}, 0x00ff00);
	else if (env->edit.brush == 1)
		draw_rect(env, (t_point){1340, 90}, (t_point){1410, 160}, 0x00ff00);
	else if (env->edit.brush == 2)
		draw_rect(env, (t_point){1440, 90}, (t_point){1510, 160}, 0x00ff00);
	else if (env->edit.brush == 3)
		draw_rect(env, (t_point){1540, 90}, (t_point){1610, 160}, 0x00ff00);
	else if (env->edit.brush == 4)
		draw_rect(env, (t_point){1640, 90}, (t_point){1710, 160}, 0x00ff00);
	else if (env->edit.brush == 5)
		draw_rect(env, (t_point){1740, 90}, (t_point){1810, 160}, 0x00ff00);
	else if (env->edit.brush == 6)
		draw_rect(env, (t_point){1840, 90}, (t_point){1910, 160}, 0x00ff00);
	else if (env->edit.brush == -1)
		draw_rect(env, (t_point){1290, 290}, (t_point){1360, 360}, 0x00ff00);
	else if (env->edit.brush == -2)
		draw_rect(env, (t_point){1415, 290}, (t_point){1485, 360}, 0x00ff00);
	else if (env->edit.brush == -3)
		draw_rect(env, (t_point){1540, 290}, (t_point){1610, 360}, 0x00ff00);
	else if (env->edit.brush == -4)
		draw_rect(env, (t_point){1665, 290}, (t_point){1735, 360}, 0x00ff00);
	draw_option2(env);
}

void	draw_map(t_env *env)
{
	int		w_tile;
	int		h_tile;
	int		x;
	int		y;

	draw_option(env);
	w_tile = HE / env->map.max_x;
	h_tile = HE / env->map.max_y;
	y = 0;
	while (y < HE)
	{
		x = 0;
		while (x < HE)
		{
			if (x % w_tile == 1 && y % h_tile == 1 && x < WE && y < HE)
				draw_rect(env, (t_point){x, y},
					(t_point){x + w_tile - 3, y + h_tile - 3}, 0xffffff);
			if (x % w_tile == 1 && y % h_tile == 1)
				draw_text(env, w_tile, h_tile, (t_point){x, y});
			x++;
		}
		y++;
	}
}
