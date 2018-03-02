/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:10:02 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:53:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char			*ft_strjoin(char *s1, const char *s2, bool free)
{
	char		*join;
	size_t		len_s2;

	if (!s1 || !s2)
		ZOMG;
	len_s2 = ft_strlen(s2);
	FAILZ(join = ft_strnew(ft_strlen(s1) + len_s2), NULL);
	join = ft_strcpy(join, s1);
	join = ft_strncat(join, s2, len_s2);
	if (free == true)
		ft_strdel(&s1);
	GIMME(join);
}
