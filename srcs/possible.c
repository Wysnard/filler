/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:58:10 by vlay              #+#    #+#             */
/*   Updated: 2018/03/03 18:58:28 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline int		check(t_info *info
						, char map, char piece, unsigned *touch)
{
	if ((map == info->opponent || !map)
		&& piece == '*')
		return (-1);
	if (map == info->player && piece == '*')
		(*touch)++;
	if (*touch > 1)
		return (-1);
	return (1);
}

static inline int		score_it(char map, char piece, int hotmap)
{
	if (map == '.' && piece == '*')
		return (hotmap);
	return (0);
}

static inline void		init_possible(int *y, intmax_t *score, unsigned *touch)
{
	*y = 0;
	*score = 0;
	*touch = 0;
}

intmax_t				possible(t_info *info
						, int hotmap[info->hauteur + 1][info->largeur + 1]
						, char map[info->hauteur + 1][info->largeur + 1]
						, int ji[2])
{
	unsigned	touch;
	intmax_t	score;
	int			x;
	int			y;

	init_possible(&y, &score, &touch);
	while (map[ji[0] + y]
		&& info->piece.r_y + y <= (int)info->piece.hauteur)
	{
		x = 0;
		while (map[ji[0] + y][ji[1] + x]
			&& info->piece.r_x + x <= (int)info->piece.largeur)
		{
			if (check(info, map[ji[0] + y][ji[1] + x]
				, info->piece.piece[info->piece.r_y + y][info->piece.r_x + x]
				, &touch) == -1)
				return (-1);
			score += score_it(map[ji[0] + y][ji[1] + x]
				, info->piece.piece[info->piece.r_y + y][info->piece.r_x + x]
				, hotmap[ji[0] + y][ji[1] + x]);
			x++;
		}
		y++;
	}
	return ((touch == 1) ? score : -1);
}
