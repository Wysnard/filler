/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:05:10 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/29 05:04:56 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

void			*ft_memcpy(void *restrict dst, const void *restrict src,
				size_t n)
{
	int			k;

	k = -1;
	while ((unsigned int)++k < n)
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	GIMME(dst);
}
