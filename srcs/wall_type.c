/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:01:00 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/03 19:05:56 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_view.h"

uint32_t	moon_wall(t_render r, char *tstr)
{
	Uint8		rgb[3];
	uint32_t	ret;

	rgb[2] = tstr[(r.nx * 3) + 512 * r.nz * 3];
	rgb[1] = tstr[(r.nx * 3) + 512 * r.nz * 3 + 1];
	rgb[0] = tstr[(r.nx * 3) + 512 * r.nz * 3 + 2];
	rgb[0] = (int)((float)rgb[0] * r.wall_light);
	rgb[1] = (int)((float)rgb[1] * r.wall_light);
	rgb[2] = (int)((float)rgb[2] * r.wall_light);
	ret = rgb[2] + rgb[1] * 256 + rgb[0] * 256 * 256;
	return (ret | 0xff000000);
}
