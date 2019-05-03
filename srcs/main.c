/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:06:02 by apelissi          #+#    #+#             */
/*   Updated: 2019/04/27 19:05:05 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

static t_env	*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(e->pe = (t_perso *)malloc(sizeof(t_perso))))
		return (NULL);
	return (e);
}

void			check_filename(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
			ft_exit(7);
		i++;
	}
}

int				main(int ac, char **av)
{
	int		fd;
	t_env	*e;

	if ((ac == 4 || ac == 5) && ft_strcmp(av[1], "-e") == 0)
	{
		if (ac == 5)
			check_filename(av[4]);
		ac == 4 ? start_edit(ft_atoi(av[2]), ft_atoi(av[3]), "Untitled")
			: start_edit(ft_atoi(av[2]), ft_atoi(av[3]), av[4]);
	}
	e = NULL;
	if (ac != 2)
		ft_exit(2);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !(e = init_env()))
		ft_exit(4);
	if (!(get_map(e->map, fd)))
		ft_exit(1);
	ft_is_perso(e->map->grid);
	ft_is_end(e->map->grid);
	init_sdl(e);
	return (0);
}
