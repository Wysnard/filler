/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:52:45 by vlay              #+#    #+#             */
/*   Updated: 2018/03/02 22:08:18 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>
#include <stdio.h>

int			*make_it_hot(t_info *info, int *hotmap, char *line)
{
	unsigned	i;

	i = 0;
	while (i < info->largeur)
	{
		hotmap[i] = (line[i] == info->opponent)
		? 0 : info->hauteur * info->largeur;
		i++;
	}
	return (hotmap);
}

void	print_map(int fd, t_info *info, char map[info->hauteur + 1][info->largeur + 1])
{
	unsigned	i;

	i = 0;
	while (i < info->hauteur)
	{
		ft_putstr_fd(map[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	print_piece(int fd, t_info *info)
{
	unsigned	i;

	i = 0;
	while (i <= info->piece.hauteur)
	{
		ft_putstr_fd(info->piece.piece[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}

int			ft_solve_it(t_info *info)
{
	char		*line;
	unsigned	i;
	char		map[info->hauteur + 1][info->largeur + 1];
	int			hotmap[info->hauteur + 1][info->largeur + 1];
	int			fd;

	i = 0;
	fd = open("log", O_CREAT | O_WRONLY | O_APPEND, S_IWUSR | S_IRUSR);
	while (get_next_line(0, &line) <= 0)
		if (line)
			free(line);
	while (i < info->hauteur)
	{
		while (get_next_line(0, &line) <= 0)
			if (line)
				free(line);
		ft_strcpy(map[i], &line[4]);
		map[i][info->largeur] = '\0';
		make_it_hot(info, hotmap[i], &line[4]);
		free(line);
		i++;
	}
	distcalc(info, hotmap);
	ft_getinfopiece(info);
	standard_it(info);
	ft_putendl_fd("JE PASSE\n", fd);
	print_map(fd, info, map);
	print_piece(fd, info);
	return (place(fd, info, hotmap, map));
}
