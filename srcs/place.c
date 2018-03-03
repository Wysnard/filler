/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:06:10 by vlay              #+#    #+#             */
/*   Updated: 2018/03/03 18:53:15 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

static inline void		init_place(int ji[2], intmax_t *max, t_best *best)
{
	ji[0] = 0;
	*max = INT_MAX;
	best->i = 0;
	best->j = 0;
}

int						place(t_info *info
	, int hotmap[info->hauteur + 1][info->largeur + 1]
	, char map[info->hauteur + 1][info->largeur + 1])
{
	int			ji[2];
	intmax_t	max;
	intmax_t	score;
	t_best		best;

	init_place(ji, &max, &best);
	while (map[ji[0]] && ji[0] + info->piece.hauteur < info->hauteur)
	{
		ji[1] = 0;
		while (map[ji[0]][ji[1]]
			&& ji[1] + info->piece.largeur < info->largeur)
		{
			if ((score = possible(info, hotmap, map, ji)) >= 0 && score < max)
			{
				max = score;
				best.j = ji[0] - info->piece.r_y;
				best.i = ji[1] - info->piece.r_x;
			}
			ji[1]++;
		}
		ji[0]++;
	}
	(max >= INT_MAX - 1) ?
	ft_printf("0 0\n") : ft_printf("%d %d\n", best.j, best.i);
	return ((max >= INT_MAX - 1 || win(info, map)) ? 0 : 1);
}
