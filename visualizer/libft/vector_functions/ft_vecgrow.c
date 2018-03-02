/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecgrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:08:39 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:43:48 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"
#include "../math_functions/math.h"

inline size_t			ft_vecgrow(t_vector *vector, size_t size)
{
	if ((size += vector->len + 1) < VEC_MIN_LIMIT
		&& VEC_MIN_LIMIT > vector->capacity)
		GIMME(ft_vecalloc(vector, VEC_MIN_LIMIT));
	else if (size > vector->capacity)
		GIMME(ft_vecalloc(vector, IS_POW2(size) ? size : ft_nextpower2(size)));
	GIMME(vector->capacity);
}
