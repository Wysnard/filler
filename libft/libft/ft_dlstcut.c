/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:11:33 by vlay              #+#    #+#             */
/*   Updated: 2017/12/18 21:17:43 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_cutit(t_list *list)
{
	if (!list)
		return ;
	list->next = NULL;
}

void			ft_dlstcut(t_list *list)
{
	if (!list)
		return ;
	ft_cutit(list->prev);
	list->prev = NULL;
}
