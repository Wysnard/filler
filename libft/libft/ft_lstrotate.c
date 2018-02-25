/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:17:55 by vlay              #+#    #+#             */
/*   Updated: 2017/12/07 02:12:42 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstrotate(t_list **alst)
{
	t_list	*tmp;
	t_list	*first;

	tmp = *alst;
	if (!tmp || !tmp->next)
		return (0);
	if (!tmp->next->next)
	{
		ft_ptrswap(&tmp->content, &tmp->next->content);
		ft_swap(&tmp->content_size, &tmp->next->content_size);
		return (1);
	}
	first = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *alst;
	(*alst)->next = NULL;
	*alst = first;
	return (1);
}
