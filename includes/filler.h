/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:56:29 by vlay              #+#    #+#             */
/*   Updated: 2018/02/25 20:57:19 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_best
{
	int			i;
	int			j;
}				t_best;

typedef struct	s_piece
{
	char		**piece;
	int			piece_y;
	int			piece_x;
	int			r_y;
	int			r_x;
	size_t		hauteur;
	size_t		largeur;
}				t_piece;

typedef struct	s_info
{
	t_piece		piece;
	char		opponent;
	char		player;
	unsigned	hauteur;
	unsigned	largeur;
}				t_info;

char			**ft_register_map(t_info *info);
void			ft_register_piece(t_info *info);
intmax_t		ft_place(t_info *info, int j, int i);
int				ft_solve_it(t_info *info);
void			ft_print(char **map, int y);
void			ft_hotmap(t_info *info);
void			ft_inttabprt(t_info *info);
int				ft_simple_solve(t_info *info);
void			ft_getinfopiece(t_info *info);
void			standard_it(t_info *info);
int				place(t_info *info
				, int hotmap[info->hauteur + 1][info->largeur + 1]
				, char map[info->hauteur + 1][info->largeur + 1]);
void			distcalc(t_info *info
				, int hotmap[info->hauteur + 1][info->largeur + 1]);

#endif
