/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:15:29 by vlay              #+#    #+#             */
/*   Updated: 2017/12/18 21:15:31 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	static	t_list	*last = NULL;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
		ft_lstadd(alst, new);
	else
	{
		if (!last)
			last = *alst;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}
