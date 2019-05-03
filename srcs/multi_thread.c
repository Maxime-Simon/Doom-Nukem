/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:48:04 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/03 18:08:13 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

int		multi_thread(t_env *e)
{
	SDL_Thread	*thread[NB_THREAD];
	int			i;

	e->deb = 0;
	i = 0;
	e->o.spr_posx = -1;
	e->mutex = SDL_CreateMutex();
	while (i < NB_THREAD)
	{
		thread[i] = SDL_CreateThread(get_view, "b", (void *)e);
		i++;
		while (i != e->deb)
			SDL_Delay(1);
	}
	i = 0;
	while (i < NB_THREAD)
	{
		if (!thread[i])
			return (i);
		SDL_WaitThread(thread[i], NULL);
		i++;
	}
	return (0);
}
