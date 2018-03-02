/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:16:08 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:55:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

static inline size_t			value_to_trim(const char *s1, const char *s2)
{
	size_t		trim;
	size_t		len;

	trim = 0;
	len = ft_strlen(s1);
	while (IS_WHITESPACE(*s1))
	{
		++trim;
		++s1;
	}
	while (IS_WHITESPACE(*s2))
	{
		++trim;
		++s2;
	}
	GIMME(trim == len * 2 ? len : trim);
}

inline char						*ft_strtrim(char *s, bool free)
{
	char		*begin;
	char		*rev;
	char		*trim;
	int			k;
	size_t		len;

	if (!s)
		ZOMG;
	begin = s;
	FAILZ(rev = ft_strrevcpy(s), NULL);
	k = -1;
	len = ft_strlen(s) - value_to_trim(s, rev);
	ft_strclr(rev);
	FAILZ(trim = ft_strnew(len), NULL);
	while (IS_WHITESPACE(*s))
		++s;
	while (len--)
	{
		*(trim + ++k) = *s;
		++s;
	}
	s = begin;
	if (free == true)
		ft_strdel(&s);
	GIMME(trim);
}
