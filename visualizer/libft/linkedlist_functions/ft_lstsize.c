/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:11:19 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:37:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

inline size_t			ft_lstsize(t_list *list)
{
	size_t		size;

	size = 0;
	while (list)
	{
		list = list->next;
		++size;
	}
	GIMME(size);
}
