#include "filler.h"
#include <limits.h>
#include <stdio.h>

intmax_t	possible(t_info *info
	, int hotmap[info->hauteur + 1][info->largeur + 1]
	, char map[info->hauteur + 1][info->largeur + 1]
	, int j, int i
	, int fd)
{
	unsigned	touch;
	intmax_t	score;
	int	x;
	int	y;

	y = 0;
	score = 0;
	touch = 0;
	while (map[j + y] && info->piece.r_y + y < info->piece.piece_y)
	{
		x = 0;
		while (map[j + y][i + x] && info->piece.r_x + x < info->piece.piece_x)
		{
			if (map[j + y][i + x] == info->opponent
				&& info->piece.piece[info->piece.r_y + y][info->piece.r_x + x] == '*')
				return (-1);
			if (map[j + y][i + x] == info->player
				&& info->piece.piece[info->piece.r_y + y][info->piece.r_x + x] == '*')
				touch++;
			if (touch > 1)
				return (-1);
			if (map[j + y][i + x] == '.'
				&& info->piece.piece[info->piece.r_y + y][info->piece.r_x + x] == '*')
				score += hotmap[j + y][i + x];
			x++;
		}
		y++;
	}
	return ((touch == 1) ? score : -1);
}

int	place(t_info *info
	, int hotmap[info->hauteur + 1][info->largeur + 1]
	, char map[info->hauteur + 1][info->largeur + 1]
	, int fd)
{
	int	i;
	int	j;
	intmax_t	max;
	intmax_t	score;
	t_best	best;

	j = 0;
	max = INT_MAX;
	best.i = 0;
	best.j = 0;
	while (map[j] && j + info->piece.hauteur <= info->hauteur)
	{
		i = 0;
		while (map[j][i] && i + info->piece.largeur <= info->largeur)
		{
			if ((score = possible(info, hotmap, map, j , i, fd)) >= 0 && score <= max)
			{
				max = score;
				best.j = j - info->piece.r_y;
				best.i = i - info->piece.r_x;
			}
			i++;
		}
		j++;
	}
	dprintf(fd, "SCORE = %jd | PLACEMENT = %d %d\n", max, best.j, best.i);
	(max >= INT_MAX - 1) ?
	ft_printf("0 0\n") :
	ft_printf("%d %d\n", best.j, best.i);
	return ((max >= INT_MAX - 1) ? 0 : 1);
}
