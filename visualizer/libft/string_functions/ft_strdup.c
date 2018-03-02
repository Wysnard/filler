/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:04:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:52:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		len;

	len = ft_strlen(s1);
	FAILZ(s2 = ft_strnew(len), NULL);
	while (*s1)
	{
		*s2 = *s1;
		++s1;
		++s2;
	}
	GIMME(s2 - len);
}
