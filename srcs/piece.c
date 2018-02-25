/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:04:14 by vlay              #+#    #+#             */
/*   Updated: 2018/02/25 19:05:10 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

void	ft_getinfopiece(t_info *info)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	if (line)
	{
		info->piece.piece_y = ft_atoim(ft_strchr(line, ' ') + 1);
		info->piece.piece_x = ft_atoim(ft_strrchr(line, ' ') + 1);
		free(line);
	}
	else
	{
		info->piece.piece_y = -1;
		info->piece.piece_x = -1;
	}
	i = 0;
	info->piece.piece =
		(char **)malloc(sizeof(char *) * (info->piece.piece_y + 1));
	while (i < info->piece.piece_y)
	{
		get_next_line(0, &line);
		info->piece.piece[i++] = line;
	}
	info->piece.piece[i] = NULL;
}

void	standard_it(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	info->piece.r_y = INT_MAX;
	info->piece.r_x = INT_MAX;
	info->piece.largeur = 0;
	info->piece.hauteur = 0;
	while (info->piece.piece[j])
	{
		if (ft_strchr(info->piece.piece[j], '*'))
		{
			if (j < info->piece.r_y)
				info->piece.r_y = j;
			if ((i = ft_strchri(info->piece.piece[j], '*')) < info->piece.r_x)
				info->piece.r_x = i;
			if (ft_strclen(info->piece.piece[j], '*') > info->piece.largeur)
				info->piece.largeur = ft_strclen(info->piece.piece[j], '*');
			info->piece.hauteur++;
		}
		j++;
	}
}
