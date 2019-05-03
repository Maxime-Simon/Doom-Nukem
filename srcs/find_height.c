/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:24:27 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/02 20:07:32 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

int		find_height(char c)
{
	if (c == '0' || c == '@' || c == 0)
		return (0);
	if ((c >= 'A' && c <= 'Z') || c == 'Z')
		return (2);
	else if (c >= 'a' && c <= 'o')
		return ((c - 'a' + 1) * (TS / 8));
	else if (c == 'p')
		return (TS);
	else if (c == 's')
		return (1);
	else if (c == 'z')
		return (TS * 2);
	else if (c == 't' || c == '8')
		return (TS - 1);
	else
		return (TS);
}
