/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 21:30:33 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/03 22:49:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"
#include "../memory_functions/memory.h"

inline t_list			*ft_lstnew(const void *data, size_t data_size)
{
	t_list		*list;

	FAILZ(list = (t_list *)ft_memalloc(sizeof(t_list)), NULL);
	if (data)
	{
		FAILZ(list->data = malloc(data_size), NULL);
		list->data = ft_memmove(list->data, data, data_size);
		list->data_size = data_size;
	}
	GIMME(list);
}
