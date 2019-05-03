/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:08:17 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/21 16:04:00 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "doom.h"

typedef	struct		s_dist
{
	float			xm;
	float			ym;
	float			ya;
	int				tx;
	float			am;
	float			bm;
	float			xa;
	int				ty;
}					t_dist;

/*
**	init_search_impacts.c
*/
t_dist				init_search(t_ray r, t_column c);

#endif
