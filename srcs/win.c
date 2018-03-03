/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:54:43 by vlay              #+#    #+#             */
/*   Updated: 2018/03/03 16:58:52 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	win(t_info *info, char map[info->hauteur + 1][info->largeur + 1])
{
	unsigned	j;
	unsigned	me;
	unsigned	ennemy;

	j = 0;
	me = 0;
	ennemy = 0;
	while (j <= info->hauteur)
	{
		if ((me += ft_strclen(map[j], info->player))
		> (info->hauteur * info->largeur) / 2)
			return (1);
		j++;
	}
	return (0);
}
