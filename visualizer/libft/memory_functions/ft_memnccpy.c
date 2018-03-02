/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:16:02 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/29 05:05:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

size_t			ft_memnccpy(void *dst, const void *src, int c, size_t n)
{
	int			k;
	size_t		len;

	if (!dst || !src)
		KTHXBYE;
	k = -1;
	len = 0;
	while ((unsigned int)++k < n)
	{
		++len;
		if (*((unsigned char *)src + k) == (unsigned char)c)
		{
			*((unsigned char *)dst + k) = '\0';
			break ;
		}
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	}
	*((unsigned char *)dst + k) = '\0';
	GIMME(len);
}
