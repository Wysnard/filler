/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:11:47 by vlay              #+#    #+#             */
/*   Updated: 2017/12/18 21:17:26 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (!list || !(*list))
	{
		ft_lstadd(list, new);
		(*list)->next = *list;
		(*list)->prev = *list;
	}
	else if (!(*list)->prev)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		ft_lstadd(list, new);
		(*list)->prev = tmp;
		tmp->next = *list;
	}
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
		*list = new;
	}
}
