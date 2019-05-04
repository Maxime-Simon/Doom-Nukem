/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <apelissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/04 13:24:06 by maxsimon         ###   ########.fr       */
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
	{
		ft_putstr("usage :\t./doom-nukem <filename>\n");
		ft_putstr("edit :\t./doom-nukem -e <x> <y> <name>\n");
	}
	if (i == 3)
		ft_putstr("Esc Pressed\n");
	if (i == 4)
		ft_putstr("Invalid Fd\n");
	if (i == 5)
		ft_putstr("Texture error\n");
	if (i == 6)
		ft_putstr("Level finished\n");
	if (i == 7)
		ft_putendl("Wrong filename");
	if (i == 8)
		ft_putendl(SDL_GetError());
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

void	ft_is_end(char **grid)
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
			if (grid[i][j] == 'Z')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		ft_exit(1);
}
