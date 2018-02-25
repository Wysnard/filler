/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:57:22 by vlay              #+#    #+#             */
/*   Updated: 2017/12/19 15:42:55 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	swp(int tableau[], int a, int b)
{
	int	temp;

	temp = tableau[a];
	tableau[a] = tableau[b];
	tableau[b] = temp;
}

void			ft_qsort(int tableau[], int begin, int end)
{
	int	left;
	int	right;
	int	pivot;

	left = begin - 1;
	right = end + 1;
	pivot = tableau[begin];
	if (begin >= end)
		return ;
	while (1)
	{
		while (tableau[--right] > pivot)
			;
		while (tableau[++left] < pivot)
			;
		if (left < right)
			swp(tableau, left, right);
		else
			break ;
	}
	ft_qsort(tableau, begin, right);
	ft_qsort(tableau, right + 1, end);
}
