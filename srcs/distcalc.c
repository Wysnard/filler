/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distcalc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:05:18 by vlay              #+#    #+#             */
/*   Updated: 2018/02/25 19:05:51 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline unsigned	lookat1(t_info *info
	, int hotmap[info->hauteur + 1][info->largeur + 1]
	, unsigned i, unsigned j)
{
	unsigned	chg;

	chg = 0;
	if (j > 0 && hotmap[j - 1][i] > hotmap[j][i] + 1)
	{
		hotmap[j - 1][i] = hotmap[j][i] + 1;
		chg++;
	}
	if (i > 0 && hotmap[j][i - 1] > hotmap[j][i] + 1)
	{
		hotmap[j][i - 1] = hotmap[j][i] + 1;
		chg++;
	}
	if (j < info->hauteur - 1 && hotmap[j + 1][i] > hotmap[j][i] + 1)
	{
		hotmap[j + 1][i] = hotmap[j][i] + 1;
		chg++;
	}
	if (i < info->largeur - 1 && hotmap[j][i + 1] > hotmap[j][i] + 1)
	{
		hotmap[j][i + 1] = hotmap[j][i] + 1;
		chg++;
	}
	return (chg);
}

static inline unsigned	lookat2(t_info *info
	, int hotmap[info->hauteur + 1][info->largeur + 1]
	, unsigned i, unsigned j)
{
	unsigned	chg;

	chg = 0;
	if (j > 0 && i > 0 && hotmap[j - 1][i - 1] > hotmap[j][i] + 1)
	{
		hotmap[j - 1][i - 1] = hotmap[j][i] + 1;
		chg++;
	}
	if (j > 0 && i < info->largeur - 1
		&& hotmap[j - 1][i + 1] > hotmap[j][i] + 1)
	{
		hotmap[j - 1][i + 1] = hotmap[j][i] + 1;
		chg++;
	}
	if (i > 0 && j < info->hauteur - 1
		&& hotmap[j + 1][i - 1] > hotmap[j][i] + 1)
	{
		hotmap[j + 1][i - 1] = hotmap[j][i] + 1;
		chg++;
	}
	return (chg);
}

static inline unsigned	lookat3(t_info *info
	, int hotmap[info->hauteur + 1][info->largeur + 1]
	, unsigned i, unsigned j)
{
	unsigned	chg;

	chg = 0;
	if (j < info->hauteur - 1 && i < info->largeur - 1
		&& hotmap[j + 1][i + 1] > hotmap[j][i] + 1)
	{
		hotmap[j + 1][i + 1] = hotmap[j][i] + 1;
		chg++;
	}
	return (chg);
}

void					distcalc(t_info *info
	, int hotmap[info->hauteur + 1][info->largeur + 1])
{
	unsigned	chg;
	unsigned	i;
	unsigned	j;

	chg = 1;
	while (chg)
	{
		j = 0;
		chg = 0;
		while (j < info->hauteur)
		{
			i = 0;
			while (i < info->largeur)
			{
				if (hotmap[j][i] >= 0)
					chg += lookat1(info, hotmap, i, j)
						+ lookat2(info, hotmap, i, j)
						+ lookat3(info, hotmap, i, j);
				i++;
			}
			j++;
		}
	}
}
