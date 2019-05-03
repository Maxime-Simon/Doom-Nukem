/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapiatko <vapiatko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:40:02 by apelissi          #+#    #+#             */
/*   Updated: 2019/05/02 20:10:38 by vapiatko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom.h"

int		is_visible_wall(char c)
{
	if (c == '0')
		return (0);
	if (c == 'M' || c == 'F' || c == 'K' || c == 'T' || c == 'J' || c == 'Z')
		return (1);
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6'
		|| c == '8' || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		is_touchable_wall(char c)
{
	if (c == 'M' || c == 'F' || c == 'K'
		|| c == 'T' || c == 'J' || c == '8' || c == 'Z')
		return (0);
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
		|| c == '5' || c == '6' || c == '9' || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		is_end_wall(char c)
{
	if (c == 'E')
		return (1);
	return (0);
}
