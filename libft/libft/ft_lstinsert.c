/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:30:52 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:30:55 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **alst, t_list *new, int (*cmpf)(void *, void *))
{
	t_list	*tmp;

	if (!alst)
		return ;
	if (!(tmp = *alst) || cmpf(tmp->content, new->content) >= 0)
		ft_lstadd(alst, new);
	else
	{
		while (tmp->next && cmpf(tmp->content, new->content) < 0)
			tmp = tmp->next;
		if ((new->next = tmp->next))
			new->next->prev = new;
		new->prev = tmp;
		tmp->next = new;
	}
}
