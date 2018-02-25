/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilecdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:16:27 by vlay              #+#    #+#             */
/*   Updated: 2017/12/18 21:16:28 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pilecdel(t_pile *pile)
{
	t_list	*list;
	t_list	*last;
	void	*cont;

	cont = NULL;
	last = NULL;
	if (pile == NULL)
		return (NULL);
	if ((list = pile->first) != NULL)
	{
		if ((last = list->prev))
		{
			ft_dlstcut(list);
			last->next = list->next;
		}
		cont = list->content;
		if (list->next)
			list->next->prev = last;
		if (list->next == pile->first)
			pile->first = NULL;
		else
			pile->first = list->next;
		free(list);
	}
	return (cont);
}
