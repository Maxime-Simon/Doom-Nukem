/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:43:05 by vapiatko          #+#    #+#             */
/*   Updated: 2019/03/27 18:28:27 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	get_obj(t_env *e)
{
	if (e->map->cur_bl == 'L')
	{
		e->o.flashlight = 1;
		e->t.lighton = 1;
	}
	if (e->map->cur_bl == 'M')
	{
		e->o.map = 1;
		e->pm = 1;
	}
	if (e->map->cur_bl == 'K')
	{
		e->o.key = 1;
	}
	if (e->map->cur_bl == 'T')
	{
		e->o.tp = 1;
	}
}
