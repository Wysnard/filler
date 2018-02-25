/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:52:29 by vlay              #+#    #+#             */
/*   Updated: 2018/02/25 18:52:30 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_info_map(t_info *info)
{
	char	*line;

	if (get_next_line(0, &line) && line && ft_strnequ("Plateau", line, 7))
	{
		info->hauteur = ft_atoi(ft_strchr(line, ' ') + 1);
		info->largeur = ft_atoi(ft_strrchr(line, ' ') + 1);
	}
}

void	ft_init(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	info->player = (ft_atoi(&line[10]) == 1) ? 'O' : 'X';
	info->opponent = (info->player == 'O') ? 'X' : 'O';
	free(line);
}

int		main(void)
{
	t_info	info;
	int		solved;

	ft_init(&info);
	solved = 1;
	while (1)
	{
		if (!solved)
		{
			ft_printf("0 0\n");
			break ;
		}
		ft_get_info_map(&info);
		solved = ft_solve_it(&info);
	}
	return (0);
}
