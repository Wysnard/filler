/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:32:41 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:53:24 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*map;
	int			k;
	size_t		len;

	if (!s || !f)
		ZOMG;
	len = ft_strlen(s);
	FAILZ(map = ft_strnew(len), NULL);
	k = -1;
	while ((unsigned int)++k < len)
		*(map + k) = f(k, *(s + k));
	GIMME(map);
}
