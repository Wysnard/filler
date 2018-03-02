/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsnipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:44:30 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/03 14:25:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

inline void			ft_lstsnipe(t_list **alst, t_list *target,
					void (*del)(void *, size_t))
{
	t_list		*list;

	if (*alst == target)
	{
		*alst = target->next;
		del(target->data, target->data_size);
	}
	else
	{
		list = *alst;
		while (list->next != target)
			list = list->next;
		list->next = target->next;
		del(target->data, target->data_size);
	}
}
