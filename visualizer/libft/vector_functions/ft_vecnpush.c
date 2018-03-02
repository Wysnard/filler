/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:07:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:43:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"

inline void			*ft_vecnpush(t_vector *vector, size_t size)
{
	void		*ptr;

	FAILZ(ft_vecgrow(vector, size), NULL);
	ptr = ft_vecend(vector);
	vector->len += size;
	GIMME(ptr);
}
