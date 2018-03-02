/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:13:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:43:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"
#include "../memory_functions/memory.h"

static inline void			*ft_vecrealloc(void *ptr, size_t len, size_t zlen)
{
	void		*tmp;

	FAILZ(tmp = ft_memalloc(zlen), NULL);
	if (!ptr)
		GIMME(tmp);
	ft_memmove(tmp, ptr, len);
	ft_memdel(&ptr);
	GIMME(tmp);
}

inline size_t				ft_vecalloc(t_vector *vector, size_t size)
{
	if (vector->capacity != size)
	{
		FAILZ(vector->buff = ft_vecrealloc(vector->buff,\
			vector->len * vector->data_size, size * vector->data_size), 0);
		vector->capacity = size;
		if (vector->len > size)
			vector->len = size;
		ft_memset(vector->buff + (vector->len * vector->data_size), '\0',\
			(vector->capacity - vector->len) * vector->data_size);
	}
	GIMME(vector->capacity);
}
