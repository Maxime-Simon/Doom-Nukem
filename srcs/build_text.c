/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:02:46 by vapiatko          #+#    #+#             */
/*   Updated: 2019/05/03 15:24:24 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

void	build_text(t_env *e)
{
	e->tx.sdl_flag = SDL_MESSAGEBOX_INFORMATION;
	e->tx.start = "\"Wh... Where am I? Am I all right? Yes i think so. "
					"Nothing broken.\nI should go explore to see where i have "
					"landed.\"\n\nYou can move with the arrows and rotate "
					"the view with the mouse. You can also jump with \'Space\'"
					" and crawl with \'B\'.";
	e->tx.start2 = "\"My grand-mother told me that in a world like this, i "
					"should look for the flag. I wonder what she meant... "
					"Weird old lady.\"\n\nFind the exit.";
	e->tx.end = "\"Finally, the exit.\"\n\nCongrats, you reached the "
					"end of this level. Yaay.";
}
