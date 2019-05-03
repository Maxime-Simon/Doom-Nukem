/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <madecreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:02:55 by madecreu          #+#    #+#             */
/*   Updated: 2019/04/29 19:04:32 by madecreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/edit.h"

void	free_textures(t_env *env)
{
	SDL_FreeSurface(env->text.item0);
	SDL_FreeSurface(env->text.item1);
	SDL_FreeSurface(env->text.item2);
	SDL_FreeSurface(env->text.item3);
	SDL_FreeSurface(env->text.item4);
	SDL_FreeSurface(env->text.text0);
	SDL_FreeSurface(env->text.text1);
	SDL_FreeSurface(env->text.text2);
	SDL_FreeSurface(env->text.text3);
	SDL_FreeSurface(env->text.text4);
	SDL_FreeSurface(env->text.text5);
	SDL_FreeSurface(env->text.text6);
	SDL_FreeSurface(env->text.text7);
	SDL_FreeSurface(env->text.text8);
	SDL_FreeSurface(env->text.text9);
	SDL_FreeSurface(env->sdl.modifier);
	SDL_FreeSurface(env->sdl.to_window);
	SDL_DestroyWindow(env->sdl.win);
}

void	exit_doom(t_env *env, int value, const char *error)
{
	int i;

	i = 0;
	if (value == 1)
	{
		while (i < env->map.max_y)
		{
			free(env->map.map[i]);
			i++;
		}
	}
	if (value < 3)
		free(env->map.map);
	free_textures(env);
	if (ft_strcmp(error, "") != 0)
		ft_putendl(error);
	SDL_Quit();
	exit(3);
}

int		verif_valid_map(t_env *env)
{
	t_point	coor;
	int		i;
	int		c;

	coor.y = 0;
	i = 0;
	c = 0;
	while (coor.y++ < env->map.max_y)
	{
		coor.x = 0;
		while (coor.x++ < env->map.max_x)
		{
			if (env->map.map[coor.y - 1][coor.x - 1] == -6)
				i = 1;
			else if (env->map.map[coor.y - 1][coor.x - 1] == -8)
				c = 1;
		}
	}
	if (i != 1 || c != 1)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Nope",
			"Votre map n'est pas valide", NULL);
		return (0);
	}
	return (1);
}

void	save_and_exit(t_env *env)
{
	t_point	coor;
	int		fd;

	if (verif_valid_map(env))
	{
		fd = open(env->map.name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		ft_putnbr_fd(env->map.max_x, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(env->map.max_y, fd);
		ft_putchar_fd('\n', fd);
		coor.y = 0;
		while (coor.y++ < env->map.max_y)
		{
			coor.x = 0;
			while (coor.x++ < env->map.max_x)
				select_and_print(env->map.map[coor.y - 1][coor.x - 1], fd);
			ft_putchar_fd('\n', fd);
		}
		ft_putendl("Votre map a ete ajoutee au dossier /maps");
		close(fd);
		exit_doom(env, 4, "");
	}
}
