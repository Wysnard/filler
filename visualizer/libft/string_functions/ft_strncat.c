/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:26:12 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:55:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char			*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n)
{
	int			k;
	size_t		len;

	k = -1;
	len = ft_strlen(s1);
	while ((unsigned int)++k < n && *(s2 + k))
		*(s1 + len++) = *(s2 + k);
	*(s1 + len) = '\0';
	GIMME(s1);
}
