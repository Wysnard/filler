/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:23:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/03 22:50:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dlist.h"
#include "../memory_functions/memory.h"

inline t_dlist			*ft_dlstnew(const void *data, size_t data_size)
{
	t_dlist		*dlist;

	FAILZ(dlist = (t_dlist *)ft_memalloc(sizeof(t_dlist)), NULL);
	if (data)
	{
		FAILZ(dlist->data = malloc(data_size), NULL);
		dlist->data = ft_memmove(dlist->data, data, data_size);
		dlist->data_size = data_size;
	}
	GIMME(dlist);
}
