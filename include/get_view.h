/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:23:59 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/03 19:05:51 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_VIEW_H
# define GET_VIEW_H
# include "doom.h"

typedef struct		s_render
{
	int				nx;
	int				nz;
	int				z;
	int				wall_start;
	int				wall_end;
	float			wall_light;
}					t_render;

/*
**	print_wall.c
*/
uint32_t			render(t_render r, t_column c, t_env *e);
uint32_t			moon_wall(t_render r, char *tstr);
uint32_t			skybox(t_render r, t_column c, t_env *e);

#endif
