/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:00:10 by apelissi          #+#    #+#             */
/*   Updated: 2019/03/21 13:21:19 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

t_env	*init_env(void)
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

int		main(int ac, char **av)
{
	int		fd;
	t_env	*e;

	e = NULL;
	if (ac != 2)
		ft_exit(2);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !(e = init_env()))
		ft_exit(4);
	if (!(get_map(e->map, fd)))
		ft_exit(1);
	ft_is_perso(e->map->grid);
	init_sdl(e);
	return (0);
}
