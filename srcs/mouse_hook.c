/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:20:38 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/27 16:50:22 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

int		mouse_move_hook(SDL_Event event, t_env *e)
{
	int		x;
	int		y;

	SDL_GetMouseState(&x, &y);
	if (event.motion.xrel * (event.motion.x - e->win_x / 2) > 0)
		e->pe->angle -= event.motion.xrel / 2;
	if (event.motion.yrel * (event.motion.y - e->win_y / 2) > 0)
		e->pe->pos_z += event.motion.yrel * 2;
	return (0);
}
