/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:52:29 by vlay              #+#    #+#             */
/*   Updated: 2018/03/03 17:29:58 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static int			ft_get_info_map(t_info *info)
{
	char	*line;

	if (get_next_line(0, &line) > 0 && line && ft_strnequ("Plateau", line, 7))
	{
		info->hauteur = ft_atoi(ft_strchr(line, ' ') + 1);
		info->largeur = ft_atoi(ft_strrchr(line, ' ') + 1);
		return (1);
	}
	return (0);
}

static int			ft_init(t_info *info)
{
	char	*line;

	while (get_next_line(0, &line) < 1)
		if (line)
			free(line);
	if (line && ft_strlen(line) > 11
		&& ft_strnequ(line, "$$$ exec", 8) && ft_isdigit(line[10]))
	{
		info->player = (ft_atoi(&line[10]) == 1) ? 'O' : 'X';
		info->opponent = (info->player == 'O') ? 'X' : 'O';
	}
	else
	{
		write(2, "ERROR\n", 6);
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

static inline void	free_piece(t_info *info)
{
	unsigned	i;

	i = 0;
	while (info->piece.piece[i])
		free(info->piece.piece[i++]);
	free(info->piece.piece);
	info->piece.piece = NULL;
}

int					main(void)
{
	t_info	info;
	int		solved;

	if (!(solved = ft_init(&info)))
		return (1);
	while (solved)
	{
		if (!ft_get_info_map(&info))
		{
			write(2, "ERROR\n", 6);
			break ;
		}
		solved = ft_solve_it(&info);
		free_piece(&info);
	}
	ft_printf("0 0\n");
	return (0);
}
