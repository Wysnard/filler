/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:17:09 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:17:12 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **list)
{
	t_list	*head;
	t_list	*rev;

	rev = *list;
	if (rev && rev->next)
	{
		head = rev->next;
		ft_lstrev(&(rev->next));
		head->next = rev;
		*list = rev->next;
		head->next->next = NULL;
	}
}
