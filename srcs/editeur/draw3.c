/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:58:04 by madecreu          #+#    #+#             */
/*   Updated: 2019/04/26 16:59:11 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/edit.h"

void	draw_option5(t_env *env)
{
	draw_rect(env, (t_point){1750, 708}, (t_point){1800, 750}, 0x00ffff);
	draw_rect(env, (t_point){1850, 700}, (t_point){1900, 750}, 0x00ffff);
	draw_rect(env, (t_point){1400, 1000}, (t_point){1800, 1150}, 0x0000ff);
}

void	draw_text4(t_env *env, int w_tile, int h_tile, t_point pos)
{
	if (env->map.map[pos.y / h_tile][pos.x / w_tile] == 7)
	{
		draw_rect(env, (t_point){pos.x, pos.y},
			(t_point){pos.x + w_tile - 3, pos.y + (h_tile / 10)}, 0xffaa00);
		draw_rect(env, (t_point){pos.x, pos.y + (h_tile / 10) * 2},
			(t_point){pos.x + w_tile - 3, pos.y + (h_tile / 10) * 3}, 0xffbb00);
		draw_rect(env, (t_point){pos.x, pos.y + (h_tile / 10) * 4},
			(t_point){pos.x + w_tile - 3, pos.y + (h_tile / 10) * 5}, 0xffcc00);
		draw_rect(env, (t_point){pos.x, pos.y + (h_tile / 10) * 6},
			(t_point){pos.x + w_tile - 3, pos.y + (h_tile / 10) * 7}, 0xffdd00);
		draw_rect(env, (t_point){pos.x, pos.y + (h_tile / 10) * 8},
			(t_point){pos.x + w_tile - 3, pos.y + (h_tile / 10) * 9}, 0xffee00);
	}
}
