/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:29:16 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:54:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline size_t			ft_strlcat(char *restrict dst, const char *restrict src,
						size_t n)
{
	int			k;
	size_t		len_dst;
	size_t		len_src;
	size_t		p;

	k = -1;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	p = len_dst - 1;
	if (n < len_dst + 1)
		GIMME(len_src + n);
	while (++p < n - 1)
		*(dst + p) = *(src + ++k);
	*(dst + p) = '\0';
	GIMME(len_dst + len_src);
}
