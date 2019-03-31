/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/27 17:00:55 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	find_block(t_env *e, t_perso *p)
{
	int x;
	int y;

	x = p->pos_x / TS;
	y = p->pos_y / TS;
	e->map->cur_bl = e->map->grid[y][x];
}

int		ft_exit(int i)
{
	if (i == 1)
		ft_putstr("Invalid Map\n");
	if (i == 2)
		ft_putstr("usage : ./Wolf3D <filename>\n");
	if (i == 3)
		ft_putstr("Esc Pressed\n");
	if (i == 4)
		ft_putstr("Invalid Fd\n");
	if (i == 5)
		ft_putstr("Texture error\n");
	exit(0);
}

void	ft_is_perso(char **grid)
{
	int	i;
	int	j;
	int p;

	p = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '@')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		ft_exit(1);
}

int		set_color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	check_close_bl(t_env *e, t_perso *p)
{
	if (e->map->grid[((int)p->pos_y / TS) - 1][(int)p->pos_x / TS]  == '4' &&
			e->o.key-- > 0)
			e->map->grid[((int)p->pos_y / TS) - 1][(int)p->pos_x / TS] = '0';
	else if (e->map->grid[((int)p->pos_y / TS) + 1][(int)p->pos_x / TS] == '4' &&
			e->o.key-- > 0)
			e->map->grid[((int)p->pos_y / TS) + 1][(int)p->pos_x / TS] = '0';
	else if (e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) - 1] == '4' &&
			e->o.key-- > 0)
			e->map->grid[((int)p->pos_y) / TS][((int)p->pos_x / TS) - 1] = '0';
	else if (e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) + 1] == '4'&&
			e->o.key-- > 0)
			e->map->grid[(int)p->pos_y / TS][((int)p->pos_x / TS) + 1] = '0';
}
